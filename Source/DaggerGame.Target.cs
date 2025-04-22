// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using DaggerBuildTool;

public class DaggerGameTarget(TargetInfo target) : DaggerGameTargetRulesBase(target, null,
    rules => {
        rules.ExtraModuleNames.AddRange(new string[] {
            "DaggerGame"
        });
    });
