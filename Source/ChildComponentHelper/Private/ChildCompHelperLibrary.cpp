#include "ChildCompHelperLibrary.h"



void  UChildCompHelperLibrary::CopyChildActorCompProperties(UChildActorComponent* ChildComponent, AActor* TargetActor)
{
	// Get ChildComponent Actor Class
	UClass* ActorClass = ChildComponent->GetChildActorClass();

	AActor* SourceActor = ChildComponent->GetChildActor();
	
	// Iterate through all properties of the source actor
	for (TFieldIterator<FProperty> PropIt(ActorClass); PropIt; ++PropIt)
	{
		FProperty* Property = *PropIt;

		// Check if the property is editable and supported
		if (Property->HasAnyPropertyFlags(CPF_Edit))
		{
			void* SourceValue = Property->ContainerPtrToValuePtr<void>(SourceActor);
			void* TargetValue = Property->ContainerPtrToValuePtr<void>(TargetActor);

			// Copy the value using the property's CopyCompleteValue function
			Property->CopySingleValue(TargetValue, SourceValue);
		}
	}
}
