// Copyright Epic Games, Inc. All Rights Reserved.

#include "DaggerContextEffectsLibraryFactory.h"

#include "Feedback/ContextEffects/DaggerContextEffectsLibrary.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(DaggerContextEffectsLibraryFactory)

class FFeedbackContext;
class UClass;
class UObject;

UDaggerContextEffectsLibraryFactory::UDaggerContextEffectsLibraryFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UDaggerContextEffectsLibrary::StaticClass();

	bCreateNew = true;
	bEditorImport = false;
	bEditAfterNew = true;
}

UObject* UDaggerContextEffectsLibraryFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UDaggerContextEffectsLibrary* DaggerContextEffectsLibrary = NewObject<UDaggerContextEffectsLibrary>(InParent, Name, Flags);

	return DaggerContextEffectsLibrary;
}
