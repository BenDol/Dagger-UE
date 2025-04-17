// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/DaggerGameFeaturePolicyBase.h"

#include "DaggerGameFeaturePolicy.generated.h"

/**
 * 
 */
UCLASS(MinimalAPI, Config = Game)
class UDaggerGameFeaturePolicy : public UDaggerGameFeaturePolicyBase
{
    GENERATED_BODY()

public:
    virtual void InitGameFeatureManager() override;
};
