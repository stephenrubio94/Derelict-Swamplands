

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "DerelictCharacterBase.h"
#include "DerelictPlayerControllerBase.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class DERELICTSWAMPLANDS_API ADoor : public AInteractable
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
public:
	ADoor();
	UFUNCTION(BlueprintCallable, Category = "Actor")
		void Interact();
	UFUNCTION(BlueprintCallable, Category = "Actor")
		void UpdateMouseoverText();
	UFUNCTION(BlueprintCallable, Category = "Actor")
		void Seal();
	UFUNCTION(BlueprintCallable, Category = "Actor")
		bool CanOpenDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		bool isLocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		bool isBroken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		bool isAirtight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		int doorID;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	//	AGasBP* linkedGasBPs[2];
};
