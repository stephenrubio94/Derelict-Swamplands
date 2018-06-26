

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Subsection.h"
#include "Door.h"
#include "GasBase.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API AGasBase : public AActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:	
	AGasBase();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		float ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		float DPS;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		bool containsGas;
	bool isRoomSealed;
	bool isDamagingPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		ASubsection* subsection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		TArray<ADoor*> linkedDoors;
	
	void UpdateGasStatus();
	void ChangeGas();
	//TODO Actor begin overlap
	//TODO Actor end overlap
};
