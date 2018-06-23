// Copyright sucks

using UnrealBuildTool;
using System.Collections.Generic;

public class DerelictSwamplandsEditorTarget : TargetRules
{
	public DerelictSwamplandsEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "DerelictSwamplands" } );
	}
}
