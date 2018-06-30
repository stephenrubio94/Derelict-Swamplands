

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
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Actor")
	FText mouseOverText;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Actor")
	bool DisplayingMessage;

	UFUNCTION(BlueprintCallable, Category = "Actor")
	virtual void UpdateMouseoverText();

	UFUNCTION(BlueprintCallable, Category = "Actor")
	virtual void Interact();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	class USceneComponent* RootItem;

	class ADerelictGameModeBase* gameMode;
};
