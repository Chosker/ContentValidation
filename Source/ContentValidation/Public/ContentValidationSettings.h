#pragma once

#include "CoreMinimal.h"

#include "ContentValidationSettings.generated.h"

USTRUCT(BlueprintType)
struct FNamingConventionData
{
	GENERATED_USTRUCT_BODY()

	/** Comma-separated prefixes */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Prefixes;

	/** Comma-separated Suffixes */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Suffixes;
};

/**
 * Settings class to store configuration relative to the Content Validation
 */
UCLASS(config = ContentValidationSettings, defaultconfig)
class CONTENTVALIDATION_API UContentValidationSettings : public UObject
{
    GENERATED_BODY()

public:
    UContentValidationSettings(const FObjectInitializer& obj);

#if WITH_EDITORONLY_DATA
	/** Folder Structure Tree where every subfolder starts with -
	* Example:
	* Maps
	* -Game
	* --Sublevels
	* */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Folder Structure", meta = (MultiLine = "true"))
    FString FolderStructureTree;
	
	/** Naming Convention Class Name and Prefix/Suffix Data */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Naming Convention", DisplayName = "Naming Convention Prefix and Suffix Rules")
    TMap<FString, FNamingConventionData> NamingConventionRules;

	/** Characters allowed in Asset Filenames */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Naming Convention", DisplayName = "Characters allowed in Filename")
	FString FilenameAllowedCharacters;
#endif

};
