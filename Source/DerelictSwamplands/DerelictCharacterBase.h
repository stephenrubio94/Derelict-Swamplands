#pragma once

#include "CoreMinimal.h"
#include "ToolBase.h"
#include "Interactable.h"
#include "DerelictGameModeBase.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Camera/CameraComponent.h"
#include "DerelictCharacterBase.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API ADerelictCharacterBase : public ACharacter
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void MoveForward(float Val);
	void MoveRight(float Val);
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Actor", meta = (AllowPrivateAccess = "true"))
		class UFlashlightBase* FlashlightBase;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Actor", meta = (AllowPrivateAccess = "true"))
		class URebreatherBase* RebreatherBase;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Actor", meta = (AllowPrivateAccess = "true"))
		class UBlowtorchBase* BlowtorchBase;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Actor", meta = (AllowPrivateAccess = "true"))
		class UToolBase* equippedItem;
public:	
	ADerelictCharacterBase();
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	virtual void Tick(float DeltaTime) override;

	float BaseTurnRate;
	float BaseLookUpRate;

	void EquipItem(UToolBase* toolToEquip);
	void EquipFlashlight();
	void EquipRebreather();
	void EquipBlowtorch();
	void Reload();
	void Action();
	void Interact();
	void OpenCrafting();
	void UpdateMouseoverText();
	AInteractable* raytrace();
	void SetInGas(bool inGas, float DPS);
	void CheckGas(float deltaSeconds);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		float health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		float oxygen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		bool isInGas;
	float gasDPS;
	float moveSpeed;
	bool mouseOverTextWritten;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		TMap<EInventory, int> inventory;
};
