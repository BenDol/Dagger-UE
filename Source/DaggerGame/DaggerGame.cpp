// Copyright Epic Games, Inc. All Rights Reserved.

#include "DaggerGame.h"
#include "Modules/ModuleManager.h"

/**
 * FDaggerGameModule
 */
class FDaggerGameModule : public FDefaultGameModuleImpl
{
    virtual void StartupModule() override
    {
    }

    virtual void ShutdownModule() override
    {
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE( FDaggerGameModule, DaggerGame, "DaggerGame" );
