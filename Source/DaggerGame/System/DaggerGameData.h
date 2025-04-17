// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "System/DaggerGameDataBase.h"

#include "DaggerGameData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Const, Meta = (DisplayName = "Dagger Game Data", ShortTooltip = "Data asset containing global game data."))
class DAGGERGAME_API UDaggerGameData : public UDaggerGameDataBase
{
    GENERATED_BODY()
};
