// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterTestsActorTestHelper.h"

#include "Character/DaggerCharacter.h"
#include "Components/SkeletalMeshComponent.h"

FShooterTestsActorTestHelper::FShooterTestsActorTestHelper(APawn* Pawn)
{
	checkf(Pawn, TEXT("Pawn is invalid."));

	LyraCharacter = Cast<ADaggerCharacter>(Pawn);
	checkf(LyraCharacter, TEXT("Cannot cast Pawn to a Dagger Character."));

	UActorComponent* ActorComponent = LyraCharacter->GetComponentByClass(USkeletalMeshComponent::StaticClass());
	checkf(ActorComponent, TEXT("Cannot find SkeletalMeshComponent from the DaggerCharacter."));

	SkeletalMeshComponent = Cast<USkeletalMeshComponent>(ActorComponent);
	checkf(SkeletalMeshComponent, TEXT("Cannot cast component to SkeletalMeshComponent."));
	
	AbilitySystemComponent = LyraCharacter->GetDaggerAbilitySystemComponent();
	checkf(AbilitySystemComponent, TEXT("Dagger Character does not have a valid AbilitySystemComponent."));

	const FName CharacterSpawn = TEXT("GameplayCue.Character.Spawn");
	GameplayCueCharacterSpawnTag = FGameplayTag::RequestGameplayTag(CharacterSpawn, true);
}

bool FShooterTestsActorTestHelper::IsPawnFullySpawned()
{
	bool bIsCurrentlySpawning = AbilitySystemComponent->IsGameplayCueActive(GameplayCueCharacterSpawnTag);
	return !bIsCurrentlySpawning;
}

FShooterTestsActorInputTestHelper::FShooterTestsActorInputTestHelper(APawn* Pawn) : FShooterTestsActorTestHelper(Pawn)
{
	PawnActions = MakeUnique<FShooterTestsPawnTestActions>(Pawn);
}

void FShooterTestsActorInputTestHelper::PerformInput(InputActionType Type)
{
	switch (Type)
	{
		case InputActionType::Crouch:
			PawnActions->ToggleCrouch();
			break;
		case InputActionType::Melee:
			PawnActions->PerformMelee();
			break;
		case InputActionType::Jump:
			PawnActions->PerformJump();
			break;
		case InputActionType::MoveForward:
			PawnActions->MoveForward();
			break;
		case InputActionType::MoveBackward:
			PawnActions->MoveBackward();
			break;
		case InputActionType::StrafeLeft:
			PawnActions->StrafeLeft();
			break;
		case InputActionType::StrafeRight:
			PawnActions->StrafeRight();
			break;
		default:
			checkNoEntry();
	}
}

void FShooterTestsActorInputTestHelper::StopAllInput()
{
	PawnActions->StopAllActions();
}