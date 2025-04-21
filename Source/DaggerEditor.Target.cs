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

        ExtraModuleNames.AddRange(new string[] { "DaggerGame", "DaggerGameEditor" });

        if (!bBuildAllModules)
        {
            NativePointerMemberBehaviorOverride = PointerMemberBehavior.Disallow;
        }

        DaggerGameTarget.ApplySharedDaggerTargetSettings(this);

        // This is used for touch screen development along with the "Unreal Remote 2" app
        EnablePlugins.Add("RemoteSession");
    }
}
