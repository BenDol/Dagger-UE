// Fill out your copyright notice in the Description page of Project Settings.

#include "DaggerGameInstance.h"

#include "CommonGameplayTags.h"

void UDaggerGameInstance::ComponentManagerInit(UGameFrameworkComponentManager* ComponentManager)
{
    Super::ComponentManagerInit(ComponentManager);

    ComponentManager->RegisterInitState(DaggerGameplayTags::InitState_Spawned, false, FGameplayTag());
    ComponentManager->RegisterInitState(DaggerGameplayTags::InitState_DataAvailable, false, DaggerGameplayTags::InitState_Spawned);
    ComponentManager->RegisterInitState(DaggerGameplayTags::InitState_DataInitialized, false, DaggerGameplayTags::InitState_DataAvailable);
    ComponentManager->RegisterInitState(DaggerGameplayTags::InitState_GameplayReady, false, DaggerGameplayTags::InitState_DataInitialized);
}
