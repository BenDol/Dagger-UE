// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DaggerClientTarget : TargetRules
{
    public DaggerClientTarget( TargetInfo Target) : base(Target)
    {
        Type = TargetType.Client;

        ExtraModuleNames.AddRange(new string[] { "DaggerGame" });

        DaggerGameTarget.ApplySharedDaggerTargetSettings(this);
    }
}