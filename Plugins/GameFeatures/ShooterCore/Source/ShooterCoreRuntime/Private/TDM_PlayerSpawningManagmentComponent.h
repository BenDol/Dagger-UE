// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Player/DaggerPlayerSpawningManagerComponent.h"

#include "TDM_PlayerSpawningManagmentComponent.generated.h"

class AActor;
class AController;
class ADaggerPlayerStart;
class UObject;

/**
 * 
 */
UCLASS()
class UTDM_PlayerSpawningManagmentComponent : public UDaggerPlayerSpawningManagerComponent
{
    GENERATED_BODY()

public:

    UTDM_PlayerSpawningManagmentComponent(const FObjectInitializer& ObjectInitializer);

    virtual AActor* OnChoosePlayerStart(AController* Player, TArray<ADaggerPlayerStart*>& PlayerStarts) override;
    virtual void OnFinishRestartPlayer(AController* Player, const FRotator& StartRotation) override;

protected:

};
