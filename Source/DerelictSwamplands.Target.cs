

using UnrealBuildTool;
using System.Collections.Generic;

public class DerelictSwamplandsTarget : TargetRules
{
	public DerelictSwamplandsTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "DerelictSwamplands" } );
	}
}
