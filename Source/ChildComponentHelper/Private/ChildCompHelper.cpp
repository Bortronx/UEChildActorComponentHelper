// Fill out your copyright notice in the Description page of Project Settings.


#include "ChildCompHelper.h"
#include "ChildCompHelperLibrary.h"


// Sets default values for this component's properties
UChildCompHelper::UChildCompHelper()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UChildCompHelper::ReBuildChildActorsAtRuntime()
{
	// Get Child Actor Components from owning Actor
	TArray<UChildActorComponent*> ChildActorComponents;

	GetOwner()->GetComponents<UChildActorComponent>(ChildActorComponents);

	// Iterate through each Child Actor Component starting from the last
	for (int32 i = ChildActorComponents.Num() - 1; i >= 0; --i)
	{
		UChildActorComponent* ChildComponent = ChildActorComponents[i];

		
		// Get ChildComponent Actor Class
		UClass* ActorClass = ChildComponent->GetChildActorClass();
		// Get Relative Transform
		FTransform RelativeTransform = ChildComponent->GetRelativeTransform();
		// Get Child Actor Attach Parent
		USceneComponent* AttachParent = ChildComponent->GetAttachParent();
		

		// Spawn New Actor
		AActor* NewActor = GetWorld()->SpawnActor<AActor>(ActorClass, RelativeTransform);


		UChildCompHelperLibrary::CopyChildActorCompProperties(ChildComponent, NewActor);

		NewActor->AttachToComponent(AttachParent, FAttachmentTransformRules::KeepRelativeTransform);

		ChildComponent->DestroyComponent();
	}
}

// Called when the game starts
void UChildCompHelper::BeginPlay()
{
	Super::BeginPlay();

	if(bIsRebuildingAtRuntime)
	{
		ReBuildChildActorsAtRuntime();
	}
	
	
	
}


