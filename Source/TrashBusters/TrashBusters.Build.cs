// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TrashBusters : ModuleRules
{
	public TrashBusters(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
