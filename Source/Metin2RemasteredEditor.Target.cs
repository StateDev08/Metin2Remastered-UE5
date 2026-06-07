using UnrealBuildTool;
using System.Collections.Generic;

public class Metin2RemasteredEditorTarget : TargetRules
{
	public Metin2RemasteredEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("Metin2Remastered");
	}
}
