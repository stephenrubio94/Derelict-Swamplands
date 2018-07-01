#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Components/BoxComponent.h"
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
	float DPS;
	bool containsGas;
	bool isDamagingPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		class ASubsection* subsection;
	TArray<class ADoor*> linkedDoors;
	//TODO make fog work
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		class UStaticMeshComponent* fog;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	UBoxComponent* Box;
	
	void UpdateGasStatus();
	void ChangeGas(bool containsGas);
	UFUNCTION()
		void TriggerEnter(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
