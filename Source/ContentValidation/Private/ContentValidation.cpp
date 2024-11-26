// Copyright Epic Games, Inc. All Rights Reserved.

#include "ContentValidation.h"
#include "ISettingsModule.h"
#include "Interfaces/IPluginManager.h"
#include "ContentValidationSettings.h"

#define LOCTEXT_NAMESPACE "FContentValidationModule"

void FContentValidationModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

    // Init editor params and settings
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        SettingsModule->RegisterSettings("Project", "Plugins", "ContentValidationSettings",
            LOCTEXT("ContentValidationSettingsSettingsName", "Content Validation"), LOCTEXT("ContentValidationSettingsDescription", "Configure the Content Validation Settings"),
            GetMutableDefault<UContentValidationSettings>());
    }

	//https://biq.medium.com/configuring-unreal-engine-for-custom-shader-development-biq-cf79f72e7137
	// Fetch the absolute path to the plugins root directory.
	FString PluginBaseDirectory = IPluginManager::Get().FindPlugin(TEXT("ContentValidation"))->GetBaseDir();
	// Append the local shader directory.
	FString ShaderDirectory = FPaths::Combine(PluginBaseDirectory, TEXT("Shaders"));
	// Construct the virtual path shorthand.
	FString VirtualShaderDirectory = FString::Printf(TEXT("/Plugin/ContentValidation"));
	// Create a mapping to the virtual shader directory shorthand.
	AddShaderSourceDirectoryMapping(VirtualShaderDirectory, ShaderDirectory);
}

void FContentValidationModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Cleanup the virtual source directory mapping.
	ResetAllShaderSourceDirectoryMappings();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FContentValidationModule, ContentValidation)