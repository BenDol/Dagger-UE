// Fill out your copyright notice in the Description page of Project Settings.

#include "DaggerGameFeaturePolicy.h"

#include "Hotfix/DaggerGameFeature_HotfixManager.h"

void UDaggerGameFeaturePolicy::InitGameFeatureManager()
{
    Observers.Add(NewObject<UDaggerGameFeature_HotfixManager>());
    
    Super::InitGameFeatureManager();
}
