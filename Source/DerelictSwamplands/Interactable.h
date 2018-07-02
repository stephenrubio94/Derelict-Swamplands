#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API AInteractable : public AActor
{
	GENERATED_BODY()
	
protected:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
public:	
	AInteractable();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Actor")
	FText mouseOverText;
	bool DisplayingMessage;
	virtual void UpdateMouseoverText();
	virtual void Interact();

	class ADerelictGameModeBase* gameMode;
};
