// Copyright Legend


#include "ContentValidationFunctionLibrary.h"
#include "ContentValidationSettings.h"
#include "EditorValidatorBase.h"
#include "DataValidationModule.h"
#include "EditorValidatorHelpers.h"
#include "AssetDefinitionRegistry.h"

UClass* UContentValidationFunctionLibrary::GetParentClass(UClass* Class)
{
    if (Class != nullptr)
    {
        return Class->GetSuperClass();
    }

    return nullptr;
}

EBlueprintType UContentValidationFunctionLibrary::GetBlueprintType(UBlueprint* Blueprint)
{
    if (Blueprint != nullptr)
    {
        return Blueprint->BlueprintType;
    }

    return EBlueprintType();
}

FString UContentValidationFunctionLibrary::GetClassAssetDefinitionDisplayName(UClass* Class)
{
    if (Class != nullptr)
    {
        const UAssetDefinition* AssetDefinition = UAssetDefinitionRegistry::Get()->GetAssetDefinitionForClass(Class);
        if (AssetDefinition != nullptr)
        {
            return AssetDefinition->GetAssetDisplayName().ToString();
        }
    }
    return FString(TEXT(""));
}

void UContentValidationFunctionLibrary::GetAssetTimeStamp(FString AssetPath, FDateTime& CreationTime, FDateTime& LastAccessTime, FDateTime& LastWriteTime)
{
    FFileStatData FileStatData = IFileManager::Get().GetStatData(*AssetPath);
    CreationTime = FileStatData.CreationTime;
    LastAccessTime = FileStatData.AccessTime;
    LastWriteTime = FileStatData.ModificationTime;
}
