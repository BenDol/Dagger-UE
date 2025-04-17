// Fill out your copyright notice in the Description page of Project Settings.

#include "DaggerGameHotfixManager.h"

#include "Settings/DaggerSettingsLocal.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(DaggerGameHotfixManager)

void UDaggerGameHotfixManager::OnHotfixDeviceProfileApplied()
{
    Super::OnHotfixDeviceProfileApplied();

    UDaggerSettingsLocal* GameSettings = UDaggerSettingsLocal::Get();
    GameSettings->OnHotfixDeviceProfileApplied();
}
