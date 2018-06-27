#include "DerelictCharacterBase.h"
#include "FlashlightBase.h"
#include "RebreatherBase.h"
#include "BlowtorchBase.h"

ADerelictCharacterBase::ADerelictCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f);
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	flashlightBase = CreateDefaultSubobject<UFlashlightBase>(TEXT("FlashlightParented"));
	flashlightBase->SetupAttachment(FirstPersonCameraComponent);
	rebreatherBase = CreateDefaultSubobject<URebreatherBase>(TEXT("RebreatherParented"));
	rebreatherBase->SetupAttachment(FirstPersonCameraComponent);
	blowtorchBase = CreateDefaultSubobject<UBlowtorchBase>(TEXT("BlowtorchParented"));
	blowtorchBase->SetupAttachment(FirstPersonCameraComponent);

	isInGas = false;
	health = 100;
	moveSpeed = 10;
	mouseOverTextWritten = false;

	inventory.Add(EInventory::WiringKit, 0);
	inventory.Add(EInventory::Battery, 0);
	inventory.Add(EInventory::Kerosene, 0);
	inventory.Add(EInventory::AirFilter, 0);
}

void ADerelictCharacterBase::BeginPlay()
{
	Super::BeginPlay();	
}

void ADerelictCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckGas(DeltaTime);
	Cast<UFlashlightBase>(flashlightBase)->UpdateFlashlight(DeltaTime);
	UpdateMouseoverText();
}

void ADerelictCharacterBase::EquipItem(UToolBase* toolToEquip)
{
	if (equippedItem != nullptr)
		equippedItem->ToggleHolding();
	
	if (equippedItem != nullptr && equippedItem->GetName() == toolToEquip->GetName())
		equippedItem = nullptr;
	else
	{
		equippedItem = toolToEquip;
		equippedItem->ToggleHolding();
	}
		
}

void ADerelictCharacterBase::EquipFlashlight()
{
	EquipItem(flashlightBase);
}

void ADerelictCharacterBase::EquipRebreather()
{
	EquipItem(rebreatherBase);
}

void ADerelictCharacterBase::EquipBlowtorch()
{
	EquipItem(blowtorchBase);
}

void ADerelictCharacterBase::Reload()
{
	if (equippedItem == nullptr)
		return;
	if (inventory[equippedItem->ReloadItem] > 0)
	{
		equippedItem->Reload();
		inventory[equippedItem->ReloadItem]--;
	}
	else
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Need more items" + inventory[equippedItem->ReloadItem]));
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
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->SetMouseoverText(result->mouseOverText);
		mouseOverTextWritten = true;
	}
	else
	{
		if (mouseOverTextWritten)
			((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->SetMouseoverText(FText::FromString(""));
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
	FHitResult hitActor(ForceInit);
	FCollisionQueryParams traceParams = FCollisionQueryParams(FName(TEXT("hitActor")), true, this);
	FVector CameraLoc;
	FRotator CameraRot;
	GetActorEyesViewPoint(CameraLoc, CameraRot);

	if (GetWorld()->LineTraceSingleByChannel(hitActor, CameraLoc, CameraLoc + (CameraRot.Vector() * 200), ECC_Pawn, traceParams))
		return Cast<AInteractable>(hitActor.GetActor());
	else
		return nullptr;
}

void ADerelictCharacterBase::SetInGas(bool inGas, float DPS)
{
	isInGas = inGas;
	gasDPS = DPS;
}

void ADerelictCharacterBase::CheckGas(float deltaSeconds)
{
	if (isInGas)
		health -= deltaSeconds * gasDPS;
}

void ADerelictCharacterBase::MoveForward(float Value)
{
	if (Value != 0.0f)
		AddMovementInput(GetActorForwardVector(), Value);
}

void ADerelictCharacterBase::MoveRight(float Value)
{
	if (Value != 0.0f)
		AddMovementInput(GetActorRightVector(), Value);
}

void ADerelictCharacterBase::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ADerelictCharacterBase::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ADerelictCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ADerelictCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ADerelictCharacterBase::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ADerelictCharacterBase::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ADerelictCharacterBase::LookUpAtRate);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Inventory1", IE_Pressed, this, &ADerelictCharacterBase::EquipFlashlight);
	PlayerInputComponent->BindAction("Inventory2", IE_Pressed, this, &ADerelictCharacterBase::EquipRebreather);
	PlayerInputComponent->BindAction("Inventory3", IE_Pressed, this, &ADerelictCharacterBase::EquipBlowtorch);
	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &ADerelictCharacterBase::Action);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &ADerelictCharacterBase::Reload);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ADerelictCharacterBase::Interact);
}