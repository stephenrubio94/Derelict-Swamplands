#include "DerelictCharacterBase.h"

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

	flashlight = CreateDefaultSubobject<UFlashlightBase>(TEXT("FlashlightParented"));
	flashlight->SetupAttachment(FirstPersonCameraComponent);
	rebreather = CreateDefaultSubobject<URebreatherBase>(TEXT("RebreatherParented"));
	rebreather->SetupAttachment(FirstPersonCameraComponent);
	blowtorch = CreateDefaultSubobject<UBlowtorchBase>(TEXT("BlowtorchParented"));
	blowtorch->SetupAttachment(FirstPersonCameraComponent);

	isInGas = false;
	health = 100;
	moveSpeed = 10;
	mouseOverTextWritten = false;

	inventoryData.Add(EInventoryItemEnum::WiringKit, 0);
	inventoryData.Add(EInventoryItemEnum::Battery, 0);
	inventoryData.Add(EInventoryItemEnum::Kerosene, 0);
	inventoryData.Add(EInventoryItemEnum::AirFilter, 0);

	//Trying to get enum display text
	FText test2 = (FindObject<UEnum>(ANY_PACKAGE, TEXT("EInventoryItemEnum"), true))->GetDisplayNameTextByIndex((int)EInventoryItemEnum::AirFilter);
}

void ADerelictCharacterBase::BeginPlay()
{
	Super::BeginPlay();	
}

void ADerelictCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckGas(DeltaTime);
	//flashlight->UpdateFlashlight(DeltaTime);
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
	if (inventoryData[equippedItem->ReloadItem] > 0)
	{
		equippedItem->Reload();
		inventoryData[equippedItem->ReloadItem]--;
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Need more items" /*+ inventoryData[equippedItem->ReloadItem].toString()*/));
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