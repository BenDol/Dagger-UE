// Fill out your copyright notice in the Description page of Project Settings.

#include "DaggerGameMode.h"

#include "Character/DaggerCharacter.h"
#include "Player/DaggerPlayerController.h"
#include "Player/DaggerPlayerState.h"

ADaggerGameMode::ADaggerGameMode(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    PlayerControllerClass = ADaggerPlayerController::StaticClass();
    ReplaySpectatorPlayerControllerClass = ADaggerReplayPlayerController::StaticClass();
    PlayerStateClass = ADaggerPlayerState::StaticClass();
    DefaultPawnClass = ADaggerCharacter::StaticClass();
}
