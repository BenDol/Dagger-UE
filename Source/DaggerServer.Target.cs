// Copyright Epic Games, Inc. All Rights Reserved.

using DaggerBuildTool;
using UnrealBuildTool;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class DaggerServerTarget : DaggerServerTargetRulesBase
{
	public DaggerServerTarget(TargetInfo Target) : base(Target, "DaggerServer", 
        rules => {
            rules.ExtraModuleNames.AddRange(new string[] { "DaggerGame" });
        })
	{
		bUseChecksInShipping = true;
	}
}
