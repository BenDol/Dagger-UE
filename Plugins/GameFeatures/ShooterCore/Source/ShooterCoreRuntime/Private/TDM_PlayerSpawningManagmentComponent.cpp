// Copyright Epic Games, Inc. All Rights Reserved.

#include "TDM_PlayerSpawningManagmentComponent.h"

#include "Engine/World.h"
#include "GameFramework/PlayerState.h"
#include "GameMode/DaggerGameState.h"
#include "Player/DaggerPlayerStart.h"
#include "Teams/DaggerTeamSubsystem.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(TDM_PlayerSpawningManagmentComponent)

class AActor;

UTDM_PlayerSpawningManagmentComponent::UTDM_PlayerSpawningManagmentComponent(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

AActor* UTDM_PlayerSpawningManagmentComponent::OnChoosePlayerStart(AController* Player, TArray<ADaggerPlayerStart*>& PlayerStarts)
{
    UDaggerTeamSubsystem* TeamSubsystem = GetWorld()->GetSubsystem<UDaggerTeamSubsystem>();
    if (!ensure(TeamSubsystem))
    {
		return nullptr;
    }

    const int32 PlayerTeamId = TeamSubsystem->FindTeamFromObject(Player);

    // We should have a TeamId by now, but early login stuff before post login can try to do stuff, ignore it.
    if (!ensure(PlayerTeamId != INDEX_NONE))
    {
		return nullptr;
    }

    ADaggerGameState* GameState = GetGameStateChecked<ADaggerGameState>();

    ADaggerPlayerStart* BestPlayerStart = nullptr;
    double MaxDistance = 0;
    ADaggerPlayerStart* FallbackPlayerStart = nullptr;
    double FallbackMaxDistance = 0;

    for (APlayerState* PS : GameState->PlayerArray)
    {
		const int32 TeamId = TeamSubsystem->FindTeamFromObject(PS);
		
		// We should have a TeamId by now...
		if (PS->IsOnlyASpectator() || !ensure(TeamId != INDEX_NONE))
		{
			continue;
		}

		// If the other player isn't on the same team, lets find the furthest spawn from them.
		if (TeamId != PlayerTeamId)
		{
			for (ADaggerPlayerStart* PlayerStart : PlayerStarts)
			{
				if (APawn* Pawn = PS->GetPawn())
				{
					const double Distance = PlayerStart->GetDistanceTo(Pawn);

					if (PlayerStart->IsClaimed())
					{
						if (FallbackPlayerStart == nullptr || Distance > FallbackMaxDistance)
						{
							FallbackPlayerStart = PlayerStart;
							FallbackMaxDistance = Distance;
						}
					}
					else if (PlayerStart->GetLocationOccupancy(Player) < EDaggerPlayerStartLocationOccupancy::Full)
					{
						if (BestPlayerStart == nullptr || Distance > MaxDistance)
						{
							BestPlayerStart = PlayerStart;
							MaxDistance = Distance;
						}
					}
				}
			}
		}
    }

    if (BestPlayerStart)
    {
		return BestPlayerStart;
    }

    return FallbackPlayerStart;
}

void UTDM_PlayerSpawningManagmentComponent::OnFinishRestartPlayer(AController* Player, const FRotator& StartRotation)
{
    
}
