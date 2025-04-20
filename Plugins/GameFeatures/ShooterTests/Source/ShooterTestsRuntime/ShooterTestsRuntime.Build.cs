// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShooterTestsRuntime : ModuleRules
{
	public ShooterTestsRuntime(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CommonGame",
			"GameplayTags",
			"GameplayAbilities",
			"ModularGameplay",
            "NetCore",
            "CoreOnline",
            "DeveloperSettings",
            "UMG",
            "AIModule",
            "DaggerGame",
            "DaggerCore",
            "DaggerCharacter",
            "DaggerSystem",
        });

		PrivateDependencyModuleNames.AddRange(new string[] {
            "CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"CQTest",
			"CQTestEnhancedInput"
        });

		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.AddRange(new string[] {
                "EngineSettings",
				"LevelEditor",
				"UnrealEd"
            });
		}
	}
}
