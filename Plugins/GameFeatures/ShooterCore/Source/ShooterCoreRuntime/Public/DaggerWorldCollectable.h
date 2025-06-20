// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "Interaction/IInteractableTarget.h"
#include "Interaction/InteractionOption.h"
#include "Inventory/IPickupable.h"

#include "DaggerWorldCollectable.generated.h"

class UObject;
struct FInteractionQuery;

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class ADaggerWorldCollectable : public AActor, public IInteractableTarget, public IPickupable
{
    GENERATED_BODY()

public:

    ADaggerWorldCollectable();

    virtual void GatherInteractionOptions(const FInteractionQuery& InteractQuery, FInteractionOptionBuilder& InteractionBuilder) override;
    virtual FInventoryPickup GetPickupInventory() const override;

protected:
    UPROPERTY(EditAnywhere)
    FInteractionOption Option;

    UPROPERTY(EditAnywhere)
    FInventoryPickup StaticInventory;
};
