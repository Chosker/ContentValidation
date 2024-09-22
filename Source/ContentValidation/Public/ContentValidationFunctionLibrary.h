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

};
