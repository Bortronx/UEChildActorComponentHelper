#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ChildCompHelperLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CHILDCOMPONENTHELPER_API UChildCompHelperLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "ChildComponentHelper")
	static void CopyChildActorCompProperties(UChildActorComponent* ChildComponent, AActor* TargetActor);

};
