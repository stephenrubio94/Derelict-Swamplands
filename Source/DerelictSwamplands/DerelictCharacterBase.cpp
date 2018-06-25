#include "DerelictCharacterBase.h"

ADerelictCharacterBase::ADerelictCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	isInGas = false;
	health = 100;
	moveSpeed = 10;
	mouseOverTextWritten = false;
}

void ADerelictCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADerelictCharacterBase::StartJump()
{
	UE_LOG(LogTemp, Warning, TEXT("JUMP"));
}

void ADerelictCharacterBase::EndJump()
{
	UE_LOG(LogTemp, Warning, TEXT("JUMP"));
}

// Called every frame
void ADerelictCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADerelictCharacterBase::EquipItem(AToolBase* toolToEquip)
{
	if (equippedItem != nullptr)
		equippedItem->ToggleHolding();
	
	if (equippedItem != nullptr && equippedItem->GetActorLabel() == toolToEquip->GetActorLabel())
		equippedItem = nullptr;
	else
	{
		equippedItem = toolToEquip;
		equippedItem->ToggleHolding();
	}
		
}

void ADerelictCharacterBase::EquipFlashlight()
{
	EquipItem(flashlight);
}

void ADerelictCharacterBase::EquipRebreather()
{
	EquipItem(rebreather);
}

void ADerelictCharacterBase::EquipBlowtorch()
{
	EquipItem(blowtorch);
}

void ADerelictCharacterBase::Reload()
{
	if (equippedItem == nullptr)
		return;
	if (/*invetory.get(equippedItem->ReloadItem)*/1 > 0)
	{
		equippedItem->Reload();
		//inventory.remove(equippedItem->ReloadItem, 1);
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Need more items" /*+ equippedItem->ReloadItem.toString()*/));
}

void ADerelictCharacterBase::Action()
{
	if (equippedItem != nullptr)
		equippedItem->Use();
}

void ADerelictCharacterBase::UpdateMouseoverText()
{
	AInteractable* result = raytrace();
	if (result != nullptr)
	{
		result->UpdateMouseoverText();
		//Game Mode Hud Set Mouseover text result->mouseOverText;
		mouseOverTextWritten = true;
	}
	else
	{
		if (mouseOverTextWritten)
		{
			//Game Mode Hud Set Mouseover text to nothing;
		}
	}
}

void ADerelictCharacterBase::Interact()
{
	AInteractable* result = raytrace();
	if (result != nullptr)
		result->Interact();
}

AInteractable* ADerelictCharacterBase::raytrace()
{
	return nullptr;
}

// Called to bind functionality to input
void ADerelictCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ADerelictCharacterBase::StartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &ADerelictCharacterBase::EndJump);
	InputComponent->BindAction("Inventory1", IE_Pressed, this, &ADerelictCharacterBase::EquipFlashlight);
	InputComponent->BindAction("Inventory2", IE_Pressed, this, &ADerelictCharacterBase::EquipRebreather);
	InputComponent->BindAction("Inventory3", IE_Pressed, this, &ADerelictCharacterBase::EquipBlowtorch);
	InputComponent->BindAction("Action", IE_Pressed, this, &ADerelictCharacterBase::Action);
	InputComponent->BindAction("Reload", IE_Pressed, this, &ADerelictCharacterBase::Reload);
	InputComponent->BindAction("Interact", IE_Pressed, this, &ADerelictCharacterBase::Interact);
}