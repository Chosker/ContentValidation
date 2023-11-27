// Copyright Legend


#include "ContentValidationFunctionLibrary.h"
#include "ContentValidationSettings.h"

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

//FString UContentValidationFunctionLibrary::GetSettingTestVar()
//{
//    //void UOnaContentDBSubsystem::GetCriterionIdList(TArray<TCriterionDesc>&_CriterionIdList)
//    //{
//    //    if (auto ContentDBSettings = GetMutableDefault<UOnaContentDB_Settings>())
//    //    {
//    //        for (const auto& CriterionIt : ContentDBSettings->CriterionList)
//    //        {
//    //            _CriterionIdList.Add(TCriterionDesc(CriterionIt.Key, CriterionIt.Value));
//    //        }
//    //    }
//    //}
//
//    if (auto ContentValidationSettings = GetMutableDefault<UContentValidationSettings>())
//    {
//        return ContentValidationSettings->TestVar;
//    }
//}
