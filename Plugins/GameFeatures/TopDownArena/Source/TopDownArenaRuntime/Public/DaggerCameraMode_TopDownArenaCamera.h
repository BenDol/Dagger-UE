// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Camera/DaggerCameraMode.h"
#include "Curves/CurveFloat.h"

#include "DaggerCameraMode_TopDownArenaCamera.generated.h"

class UObject;


/**
 * UDaggerCameraMode_TopDownArenaCamera
 *
 *    A basic third person camera mode that looks down at a fixed arena.
 */
UCLASS(Abstract, Blueprintable)
class UDaggerCameraMode_TopDownArenaCamera : public UDaggerCameraMode
{
    GENERATED_BODY()

public:

    UDaggerCameraMode_TopDownArenaCamera();

protected:

    //~UDaggerCameraMode interface
    virtual void UpdateView(float DeltaTime) override;
    //~End of UDaggerCameraMode interface

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Third Person")
    float ArenaWidth;

    UPROPERTY(EditDefaultsOnly, Category = "Third Person")
    float ArenaHeight;

    UPROPERTY(EditDefaultsOnly, Category = "Third Person")
    FRotator DefaultPivotRotation;

    UPROPERTY(EditDefaultsOnly, Category = "Third Person")
    FRuntimeFloatCurve BoundsSizeToDistance;
};
