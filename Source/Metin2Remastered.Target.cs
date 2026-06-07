using UnrealBuildTool;
using System.Collections.Generic;

public class Metin2RemasteredTarget : TargetRules
{
	public Metin2RemasteredTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("Metin2Remastered");
	}
}
