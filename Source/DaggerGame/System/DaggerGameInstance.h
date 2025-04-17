// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "System/DaggerGameInstanceBase.h"

#include "DaggerGameInstance.generated.h"

/**
 * DaggerGameInstance is the game instance class for the Dagger game.
 */
UCLASS()
class DAGGERGAME_API UDaggerGameInstance : public UDaggerGameInstanceBase
{
    GENERATED_BODY()

protected:
    virtual void ComponentManagerInit(UGameFrameworkComponentManager* ComponentManager) override;
};
