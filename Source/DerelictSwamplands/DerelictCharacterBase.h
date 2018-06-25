

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FlashlightBase.h"
#include "BlowtorchBase.h"
#include "RebreatherBase.h"
#include "Interactable.h"
#include "DerelictCharacterBase.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API ADerelictCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADerelictCharacterBase();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input

	void EquipItem(AToolBase* toolToEquip);
	void EquipFlashlight();
	void EquipRebreather();
	void EquipBlowtorch();
	void Reload();
	void Action();
	void Interact();
	void UpdateMouseoverText();
	AInteractable* raytrace();

	void StartJump();
	void EndJump();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		float health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		float oxygen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		bool isInGas;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		float gasDPS;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		float moveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		bool mouseOverTextWritten;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		AFlashlightBase* flashlight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		ABlowtorchBase* blowtorch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		ARebreatherBase* rebreather;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		AToolBase* equippedItem;
};
