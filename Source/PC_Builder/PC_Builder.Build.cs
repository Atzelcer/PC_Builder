// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PC_Builder : ModuleRules
{
	public PC_Builder(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore","UMG","Slate","SlateCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
    }
}
