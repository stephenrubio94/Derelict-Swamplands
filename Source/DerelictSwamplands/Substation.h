

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "DerelictGameModeBase.h"
#include "Substation.generated.h"

/**
 * 
 */
UCLASS()
class DERELICTSWAMPLANDS_API ASubstation : public AInteractable
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	ASubstation();
	virtual void Interact() override;
	virtual void UpdateMouseoverText() override;
	bool isWorking;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	ESubstation type;
	class ADerelictCharacterBase* player;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	class ASubsection* subsection;
};
