// Copyright Epic Games, Inc. All Rights Reserved.

#include "DaggerWorldCollectable.h"

#include "Async/TaskGraphInterfaces.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(DaggerWorldCollectable)

struct FInteractionQuery;

ADaggerWorldCollectable::ADaggerWorldCollectable()
{
}

void ADaggerWorldCollectable::GatherInteractionOptions(const FInteractionQuery& InteractQuery, FInteractionOptionBuilder& InteractionBuilder)
{
    InteractionBuilder.AddInteractionOption(Option);
}

FInventoryPickup ADaggerWorldCollectable::GetPickupInventory() const
{
	return StaticInventory;
}
