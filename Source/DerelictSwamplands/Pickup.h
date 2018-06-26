

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "DerelictGameModeBase.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class DERELICTSWAMPLANDS_API APickup : public AInteractable
{
	GENERATED_BODY()
public:
	APickup();
	virtual void Interact() override;	
	EInventoryItemEnum itemType;
};
