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
	/** Characters allowed in Folder and Asset filenames. Any other characters are forbidden */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "General", DisplayName = "Allowed Characters in Folder and Filename")
	FString AllowedCharacters;

	/** Enable Validation Rules for Folder Structure */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Folder Structure", DisplayName = "Enable Validation")
	bool ValidateFolderStructure;

	/** Report any Folder Structure Errors as Warnings */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Folder Structure", DisplayName = "Report Errors as Warnings")
	bool ReportFolderStructureErrorsAsWarnings;

	/** Folder structure tree where every subfolder starts with '-'
	* Example:
	* Maps
	* -Game
	* --Sublevels
	* */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Folder Structure", meta = (MultiLine = "true"))
    FString FolderStructureTree;

	/** Comma-separated list of forbidden folder names */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Folder Structure", meta = (MultiLine = "true"))
	FString ForbiddenFolderNames;
	
	/** Enable Validation Rules for Naming Convention */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Naming Convention", DisplayName = "Enable Validation")
	bool ValidateNamingConvention;

	/** Report any Naming Convention Errors as Warnings */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Naming Convention", DisplayName = "Report Errors as Warnings")
	bool ReportNamingConventionErrorsAsWarnings;

	/** Comma-separated list of Folders (at the root level, recursive) where Naming Convention is imposed */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Naming Convention", meta = (MultiLine = "true"))
	FString NamingConventionWatchedFolders;

	/** Naming convention Class name and prefix/suffix data */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Naming Convention", DisplayName = "Naming Convention Prefix and Suffix Rules")
    TMap<FString, FNamingConventionData> NamingConventionRules;
#endif

};
