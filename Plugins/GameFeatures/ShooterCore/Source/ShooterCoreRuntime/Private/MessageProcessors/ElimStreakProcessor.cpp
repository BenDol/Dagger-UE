// Copyright Epic Games, Inc. All Rights Reserved.

#include "MessageProcessors/ElimStreakProcessor.h"

#include "GameFramework/PlayerState.h"
#include "Messages/DaggerVerbMessage.h"
#include "NativeGameplayTags.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(ElimStreakProcessor)

namespace ElimStreak
{
    UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_Dagger_Elimination_Message, "Dagger.Elimination.Message");
}

void UElimStreakProcessor::StartListening()
{
    UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(this);
    AddListenerHandle(MessageSubsystem.RegisterListener(ElimStreak::TAG_Dagger_Elimination_Message, this, &ThisClass::OnEliminationMessage));
}

void UElimStreakProcessor::OnEliminationMessage(FGameplayTag Channel, const FDaggerVerbMessage& Payload)
{
    // Track elimination streaks for the attacker (except for self-eliminations)
    if (Payload.Instigator != Payload.Target)
    {
		if (APlayerState* InstigatorPS = Cast<APlayerState>(Payload.Instigator))
		{
			int32& StreakCount = PlayerStreakHistory.FindOrAdd(InstigatorPS);
			StreakCount++;

			if (FGameplayTag* pTag = ElimStreakTags.Find(StreakCount))
			{
				FDaggerVerbMessage ElimStreakMessage;
				ElimStreakMessage.Verb = *pTag;
				ElimStreakMessage.Instigator = InstigatorPS;
				ElimStreakMessage.InstigatorTags = Payload.InstigatorTags;
				ElimStreakMessage.ContextTags = Payload.ContextTags;
 				ElimStreakMessage.Magnitude = StreakCount;

				UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(this);
				MessageSubsystem.BroadcastMessage(ElimStreakMessage.Verb, ElimStreakMessage);
			}
		}
    }

    // End the elimination streak for the target
    if (APlayerState* TargetPS = Cast<APlayerState>(Payload.Target))
    {
		PlayerStreakHistory.Remove(TargetPS);
    }
}

