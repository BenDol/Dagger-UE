// Fill out your copyright notice in the Description page of Project Settings.

#include "DaggerGameHotfixManager.h"

#include "Settings/DaggerSettingsLocal.h"

void UDaggerGameHotfixManager::OnHotfixDeviceProfileApplied()
{
    Super::OnHotfixDeviceProfileApplied();

    UDaggerSettingsLocal* GameSettings = UDaggerSettingsLocal::Get();
    GameSettings->OnHotfixDeviceProfileApplied();
}
