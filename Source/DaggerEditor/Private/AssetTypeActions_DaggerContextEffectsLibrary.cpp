// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssetTypeActions_DaggerContextEffectsLibrary.h"

#include "Feedback/ContextEffects/DaggerContextEffectsLibrary.h"

class UClass;

#define LOCTEXT_NAMESPACE "AssetTypeActions"

UClass* FAssetTypeActions_DaggerContextEffectsLibrary::GetSupportedClass() const
{
	return UDaggerContextEffectsLibrary::StaticClass();
}

#undef LOCTEXT_NAMESPACE
