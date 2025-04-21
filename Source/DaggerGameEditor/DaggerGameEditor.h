#pragma once

#include "DaggerEditorModule.h"
#include "Modules/ModuleManager.h"
#include "Logging/LogMacros.h"

DECLARE_LOG_CATEGORY_EXTERN(LogDaggerGameEditor, Log, All);

/**
 * FDaggerEditorModule
 */
class FDaggerGameEditorModule : public FDaggerEditorModule
{
public:
    virtual void StartupModule() override;

    virtual void ShutdownModule() override;
};