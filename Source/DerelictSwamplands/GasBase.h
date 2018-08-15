#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Components/BoxComponent.h"
#include "GasBase.generated.h"

//Gas volume.  One exists in every room.

UCLASS()
class DERELICTSWAMPLANDS_API AGasBase : public AActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:	
	AGasBase();
	virtual void Tick(float DeltaTime) override;
	float DPS;
	//If room contains harmful gas or not
	bool containsGas;
	bool isDamagingPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		class ASubsection* subsection;
	//Array of doors connected to this gas volume
	TArray<class ADoor*> linkedDoors;

	//TODO, eventually will display gas/fog effect
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		class UStaticMeshComponent* fog;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	UBoxComponent* Box;
	
	//Checks to see if adjacent, unsealed rooms have lethal gas, if so, this room has lethal gas
	void UpdateGasStatus();
	//Changes gas status
	void ChangeGas(bool containsGas);
	//When player enters this gas volume, sets in gas, and sets DPS.
	UFUNCTION()
	void TriggerEnter(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
