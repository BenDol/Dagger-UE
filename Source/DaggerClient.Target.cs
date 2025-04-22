// Copyright Epic Games, Inc. All Rights Reserved.

using DaggerBuildTool;
using UnrealBuildTool;

public class DaggerClientTarget : DaggerClientTargetRulesBase
{
    public DaggerClientTarget( TargetInfo Target) : base(Target, "DaggerClient",
        rules => {
            rules.ExtraModuleNames.AddRange(new string[] { "DaggerGame" });
        })
    {
        //
    }
}