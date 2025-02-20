// Copyright Legend


#include "ContentValidationFunctionLibrary.h"
#include "ContentValidationSettings.h"
#include "EditorValidatorBase.h"
#include "DataValidationModule.h"
#include "EditorValidatorHelpers.h"
#include "AssetDefinitionRegistry.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"

#define LOCTEXT_NAMESPACE "ContentValidation"

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

//#if PLATFORM_WINDOWS
//static TWeakPtr<SNotificationItem> ValidationNotificationPtr;
//#endif

void UContentValidationFunctionLibrary::ShowValidationNotification(const FText& Message, const FText& SubText, const FString& HyperlinkURL, const FText& HyperlinkText)
{
    /** Utility functions for the notification */
    //struct Local
    //{
    //    static void OnNotificationDismissed()
    //    {
    //        TSharedPtr<SNotificationItem> NotificationItem = ValidationNotificationPtr.Pin();

    //        if (NotificationItem.IsValid())
    //        {
    //            NotificationItem->Fadeout();

    //            ValidationNotificationPtr.Reset();
    //        }
    //    }
    //};

    FNotificationInfo Info(Message);
    Info.SubText = SubText;
    //Info.bFireAndForget = false;
    Info.bFireAndForget = true;
    Info.FadeOutDuration = 1.0f;
    //Info.ExpireDuration = 0.0f;
    Info.ExpireDuration = 20.0f;
    //Info.ButtonDetails.Add(FNotificationButtonInfo(LOCTEXT("OK", "OK"), FText::GetEmpty(), FSimpleDelegate::CreateStatic(&Local::OnNotificationDismissed), SNotificationItem::CS_Fail));

	if (!HyperlinkURL.IsEmpty() && !HyperlinkText.IsEmpty())
	{
        Info.HyperlinkText = HyperlinkText;
        Info.Hyperlink = FSimpleDelegate::CreateLambda([HyperlinkURL]()
        {
			FPlatformProcess::LaunchURL(*HyperlinkURL, nullptr, nullptr);
        });
	}

    //ValidationNotificationPtr = FSlateNotificationManager::Get().AddNotification(Info);
    //ValidationNotificationPtr.Pin()->SetCompletionState(SNotificationItem::CS_Fail);

	FSlateNotificationManager::Get().AddNotification(Info)->SetCompletionState(SNotificationItem::CS_Fail);
}
