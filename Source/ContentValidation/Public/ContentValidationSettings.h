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

	/** Report any Validation Errors as Warnings */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "General", DisplayName = "Report Errors as Warnings")
	bool ReportErrorsAsWarnings;

	/** Enable skipping validation of files submitted before a specific date */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "General", DisplayName = "Skip Validating Files Prior to Date")
    bool SkipFilesPriorToDate;

	/** If skipping files prior to date is enabled, the Date used to compare against */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "General", DisplayName = "Skip Validation Submit Date", meta = (EditCondition = "SkipFilesPriorToDate"))
	FDateTime SkipFilesDate;

	/** Enable Validation Rules for Folder Structure */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Folder Structure", DisplayName = "Enable Folder Structure Validation")
	bool ValidateFolderStructure;

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

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Folder Structure", DisplayName = "Notification Hyperlink Message")
    FText FolderStructureNotificationHyperlinkLabel;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Folder Structure", DisplayName = "Notification Hyperlink URL")
	FString FolderStructureNotificationHyperlinkURL;
	
	/** Enable Validation Rules for Naming Convention */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Naming Convention", DisplayName = "Enable Naming Convention Validation")
	bool ValidateNamingConvention;

	/** Comma-separated list of Folders (at the root level, recursive) where Naming Convention is imposed */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Naming Convention", meta = (MultiLine = "true"))
	FString NamingConventionWatchedFolders;

	/** Naming convention Class name and prefix/suffix data */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Naming Convention", DisplayName = "Naming Convention Prefix and Suffix Rules")
    TMap<FString, FNamingConventionData> NamingConventionRules;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Naming Convention", DisplayName = "Notification Hyperlink Message")
    FText NamingConventionNotificationHyperlinkLabel;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Naming Convention", DisplayName = "Notification Hyperlink URL")
    FString NamingConventionNotificationHyperlinkURL;

	/** Enable Validation Rules for Textures */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Textures", DisplayName = "Enable Power of 2 Texture Validation")
	bool ValidatePow2Textures;

	/** Enable Validation Rules for Textures */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Source File", DisplayName = "Enable Source Asset File Validation")
	bool ValidateSourceFile;
#endif

};
