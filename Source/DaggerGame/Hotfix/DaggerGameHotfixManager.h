// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Hotfix/DaggerHotfixManager.h"

#include "DaggerGameHotfixManager.generated.h"

/**
 * This class is used to manage hotfixes in the DaggerGame project.
 */
UCLASS()
class DAGGERGAME_API UDaggerGameHotfixManager : public UDaggerHotfixManager
{
    GENERATED_BODY()

protected:
    virtual void OnHotfixDeviceProfileApplied() override;
};
