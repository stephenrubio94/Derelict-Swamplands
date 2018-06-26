

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "DerelictGameModeBase.h"
#include "DerelictCharacterBase.h"
#include "Kismet/GameplayStatics.h"
#include "Subsection.h"
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	bool isWorking;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	ESubstation type;
	ASubsection* subsection;
	ADerelictCharacterBase* player;	
};
