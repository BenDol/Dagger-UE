// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DaggerEditorTarget : TargetRules
{
    public DaggerEditorTarget( TargetInfo Target) : base(Target)
    {
		Type = TargetType.Editor;
        
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;

        ExtraModuleNames.AddRange(new string[] { "DaggerGame", "DaggerEditor" });

        if (!bBuildAllModules)
        {
            NativePointerMemberBehaviorOverride = PointerMemberBehavior.Disallow;
        }

        DaggerGameTarget.ApplySharedLyraTargetSettings(this);

        // This is used for touch screen development along with the "Unreal Remote 2" app
        EnablePlugins.Add("RemoteSession");
        RegisterModulesCreatedByRider();
    }

    private void RegisterModulesCreatedByRider() {
        ExtraModuleNames.AddRange(new string[] { "DaggerEditor", "DaggerEditor" });
    }
}
