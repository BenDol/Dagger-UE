// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;
using DaggerBuildTool;

public class DaggerEditorTarget : DaggerEditorTargetRulesBase
{
    public DaggerEditorTarget( TargetInfo Target) : base(Target, "DaggerGameEditor", 
        rules => {
            rules.ExtraModuleNames.AddRange(new string[] { "DaggerGame", "DaggerGameEditor" });
            
            if (!rules.bBuildAllModules)
            {
                rules.NativePointerMemberBehaviorOverride = PointerMemberBehavior.Disallow;
            }
        })
    {
        //
    }
}
