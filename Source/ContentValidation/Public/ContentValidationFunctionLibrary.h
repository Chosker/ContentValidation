// Copyright Legend

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ContentValidationFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CONTENTVALIDATION_API UContentValidationFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static UClass* GetParentClass(UClass* Class);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static EBlueprintType GetBlueprintType(UBlueprint* Blueprint);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FString GetClassAssetDefinitionDisplayName(UClass* Class);

	UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetAssetTimeStamp(FString AssetPath, FDateTime& CreationTime, FDateTime& LastAccessTime, FDateTime& LastWriteTime);

	UFUNCTION(BlueprintCallable, BlueprintPure)
    static FAssetData FindAssetData(const FString& AssetPath);

	UFUNCTION(BlueprintCallable)
    static void ShowValidationNotification(const FText& Message, const FText& SubText, const FString& HyperlinkURL, const FText& HyperlinkText);
};
