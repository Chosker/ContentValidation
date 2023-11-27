// Copyright Epic Games, Inc. All Rights Reserved.

#include "ContentValidation.h"
#include "ISettingsModule.h"
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
}

void FContentValidationModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FContentValidationModule, ContentValidation)