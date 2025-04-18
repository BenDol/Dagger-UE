// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMode/DaggerGameModeBase.h"

#include "DaggerGameMode.generated.h"

/**
 * 
 */
UCLASS(Config = Game, Meta = (ShortTooltip = "The base game mode class used by this project."), BlueprintType, Blueprintable)
class DAGGERGAME_API ADaggerGameMode : public ADaggerGameModeBase
{
    GENERATED_BODY()

public:
    ADaggerGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
