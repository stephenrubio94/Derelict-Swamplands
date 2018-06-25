

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractable();

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tool")
	FString mouseoverText;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tool")
	bool DisplayingMessage;

	UFUNCTION(BlueprintCallable, Category = "Actor")
	virtual void UpdateMouseoverText();

	UFUNCTION(BlueprintCallable, Category = "Actor")
	virtual void Interact();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	class USceneComponent* RootItem;
};
