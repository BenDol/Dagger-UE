// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DaggerServerEOSTarget : DaggerServerTarget
{
	public DaggerServerEOSTarget(TargetInfo Target) : base(Target)
	{
		CustomConfig = "EOS";
	}
}
