#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "DerelictGameModeBase.h"
#include "DerelictCharacterBase.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include "Door.generated.h"


UCLASS()
class DERELICTSWAMPLANDS_API ADoor : public AInteractable
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
public:
	ADoor();
	void Interact();
	void UpdateMouseoverText();
	void Seal();
	bool CanOpenDoor();

	bool isLocked;
	bool isBroken;
	bool isAirtight;
	bool isOpen;
	TArray<class AGasBase*> linkedGasBPs;
	class ASubsection* subsection;
	FVector doorOpen;
	FVector doorClosed;

	UFUNCTION()
		void TimelineUpdate(float value);
	UFUNCTION()
		void TimelineFinished();
	UPROPERTY()
		TEnumAsByte<ETimelineDirection::Type> TimelineDirection;
	
	class UTimelineComponent* doorOpenTimeline;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UCurveFloat* DoorOpenCurve;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UStaticMeshComponent* doorMesh;
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UStaticMeshComponent* doorFrame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* DoorOpenSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* DoorLockedSound;
};
