// Copyright Epic Games, Inc. All Rights Reserved.

#include "MessageProcessors/AssistProcessor.h"

#include "GameFramework/PlayerState.h"
#include "Messages/DaggerVerbMessage.h"
#include "Messages/DaggerVerbMessageHelpers.h"
#include "NativeGameplayTags.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(AssistProcessor)

UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_Lyra_Elimination_Message, "Lyra.Elimination.Message");
UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_Lyra_Damage_Message, "Lyra.Damage.Message");
UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_Lyra_Assist_Message, "Lyra.Assist.Message");

void UAssistProcessor::StartListening()
{
    UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(this);
    AddListenerHandle(MessageSubsystem.RegisterListener(TAG_Lyra_Elimination_Message, this, &ThisClass::OnEliminationMessage));
    AddListenerHandle(MessageSubsystem.RegisterListener(TAG_Lyra_Damage_Message, this, &ThisClass::OnDamageMessage));
}

void UAssistProcessor::OnDamageMessage(FGameplayTag Channel, const FDaggerVerbMessage& Payload)
{
    if (Payload.Instigator != Payload.Target)
    {
		if (APlayerState* InstigatorPS = UDaggerVerbMessageHelpers::GetPlayerStateFromObject(Payload.Instigator))
		{
			if (APlayerState* TargetPS = UDaggerVerbMessageHelpers::GetPlayerStateFromObject(Payload.Target))
			{
				FPlayerAssistDamageTracking& Damage = DamageHistory.FindOrAdd(TargetPS);
				float& DamageTotalFromTarget = Damage.AccumulatedDamageByPlayer.FindOrAdd(InstigatorPS);
				DamageTotalFromTarget += Payload.Magnitude;
			}
		}
    }
}

void UAssistProcessor::OnEliminationMessage(FGameplayTag Channel, const FDaggerVerbMessage& Payload)
{
    if (APlayerState* TargetPS = Cast<APlayerState>(Payload.Target))
    {
		// Grant an assist to each player who damaged the target but wasn't the instigator
		if (FPlayerAssistDamageTracking* DamageOnTarget = DamageHistory.Find(TargetPS))
		{
			for (const auto& KVP : DamageOnTarget->AccumulatedDamageByPlayer)
			{
				if (APlayerState* AssistPS = KVP.Key)
				{
					if (AssistPS != Payload.Instigator)
					{
						FDaggerVerbMessage AssistMessage;
						AssistMessage.Verb = TAG_Lyra_Assist_Message;
						AssistMessage.Instigator = AssistPS;
						//@TODO: Get default tags from a player state or save off most recent tags during assist damage?
						//AssistMessage.InstigatorTags = ;
						AssistMessage.Target = TargetPS;
						AssistMessage.TargetTags = Payload.TargetTags;
						AssistMessage.ContextTags = Payload.ContextTags;
						AssistMessage.Magnitude = KVP.Value;

						UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(this);
						MessageSubsystem.BroadcastMessage(AssistMessage.Verb, AssistMessage);
					}
				}
			}

			// Clear the damage log for the eliminated player
			DamageHistory.Remove(TargetPS);
		}
    }
}

