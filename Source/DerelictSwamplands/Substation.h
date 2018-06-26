

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
	
public:
	ASubstation();
	virtual void Interact() override;
	virtual void BeginPlay() override;
	bool isWorking;
	ESubstation type;
	//Subsection* subsection;
	
	
};
