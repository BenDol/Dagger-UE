// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TopDownArenaRuntime : ModuleRules
{
    public TopDownArenaRuntime(ReadOnlyTargetRules Target) : base(Target)
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
            "GameplayTags",
            "NetCore",
            "CoreOnline",
            "Niagara",
            "DeveloperSettings",
            "UMG",
            "DaggerGame",
            "DaggerCore",
            "DaggerCharacter",
            "DaggerCamera",
        });
        
		PrivateDependencyModuleNames.AddRange(new string[] {
            "CoreUObject",
			"Engine",
			"Slate",
			"SlateCore",
			"GameplayAbilities",
			"GameplayTags",
			"Niagara",
        });
        
		DynamicallyLoadedModuleNames.AddRange(new string[] {
            // ... add any modules that your module loads dynamically here ...
        });
    }
}
