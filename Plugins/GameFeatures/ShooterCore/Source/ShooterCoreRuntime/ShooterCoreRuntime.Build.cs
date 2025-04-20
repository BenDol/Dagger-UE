// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShooterCoreRuntime : ModuleRules
{
    public ShooterCoreRuntime(ReadOnlyTargetRules Target) : base(Target)
    {
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(new string[] {
            // ... add public include paths required here ...
        });
        
		PrivateIncludePaths.AddRange(new string[] {
            // ... add other private include paths required here ...
        });
        
		PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
			"DaggerGame",
			"DaggerCore",
			"DaggerMessages",
			"DaggerInput",
			"DaggerSystem",
			"ModularGameplay",
			"GameplayMessageRuntime",
			"CommonGame",
            "GameplayTags",
        });
        
		PrivateDependencyModuleNames.AddRange(new string[] {
            "CoreUObject",
			"Engine",
			"Slate",
			"SlateCore",
			"GameplayTags",
			"GameplayTasks",
			"GameplayAbilities",
			"GameplayMessageRuntime",
			"CommonUI",
			"UMG",
			"DataRegistry",
			"AsyncMixin",
			"EnhancedInput",
			"GameSubtitles",
			"DeveloperSettings",
			"AIModule",
            "DaggerMessages",
            "DaggerCharacter",
            "DaggerSettings",
            "NetCore",
            "CoreOnline",
            "AIModule",
        });
    }
}
