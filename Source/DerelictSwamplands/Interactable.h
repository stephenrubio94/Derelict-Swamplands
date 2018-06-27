

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	AInteractable();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	FText mouseOverText;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	bool DisplayingMessage;

	UFUNCTION(BlueprintCallable, Category = "Actor")
	virtual void UpdateMouseoverText();

	UFUNCTION(BlueprintCallable, Category = "Actor")
	virtual void Interact();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	class USceneComponent* RootItem;
};
