// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class DaggerServerTarget : TargetRules
{
	public DaggerServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;

		ExtraModuleNames.AddRange(new string[] { "DaggerGame" });

		DaggerGameTarget.ApplySharedDaggerTargetSettings(this);

		bUseChecksInShipping = true;
	}
}
