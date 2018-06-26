

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "DerelictGameModeBase.h"
#include "DerelictCharacterBase.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class DERELICTSWAMPLANDS_API APickup : public AInteractable
{
	GENERATED_BODY()
public:
	virtual void Interact() override;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	EInventory itemType;
};
