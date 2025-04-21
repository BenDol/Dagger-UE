// Copyright Epic Games, Inc. All Rights Reserved.

#include "DaggerGameEditor.h"

#include "Engine/GameInstance.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "ToolMenu.h"
#include "ToolMenus.h"
#include "DaggerEditorModule.h"
#include "UObject/UObjectIterator.h"

DEFINE_LOG_CATEGORY(LogDaggerGameEditor);

#define LOCTEXT_NAMESPACE "DaggerGameEditor"

void FDaggerGameEditorModule::StartupModule()
{
    FDaggerEditorModule::StartupModule();
}

void FDaggerGameEditorModule::ShutdownModule()
{
    FDaggerEditorModule::ShutdownModule();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FDaggerGameEditorModule, DaggerGameEditor);