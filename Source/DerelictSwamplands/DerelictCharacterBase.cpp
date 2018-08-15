#include "DerelictCharacterBase.h"
#include "FlashlightBase.h"
#include "RebreatherBase.h"
#include "BlowtorchBase.h"
#include "DerelictPlayerControllerBase.h"

ADerelictCharacterBase::ADerelictCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	//Sets up camera
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f);
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	//Sets up all tool attachments
	FlashlightBase = CreateDefaultSubobject<UFlashlightBase>(TEXT("FlashlightParented"));
	FlashlightBase->SetupAttachment(FirstPersonCameraComponent);
	FlashlightBase->RelativeLocation = FVector(20.0f, 0.0f, 0.0f);
	RebreatherBase = CreateDefaultSubobject<URebreatherBase>(TEXT("RebreatherParented"));
	RebreatherBase->SetupAttachment(FirstPersonCameraComponent);
	BlowtorchBase = CreateDefaultSubobject<UBlowtorchBase>(TEXT("BlowtorchParented"));
	BlowtorchBase->SetupAttachment(FirstPersonCameraComponent);

	isInGas = false;
	health = 100;
	moveSpeed = 10;
	mouseOverTextWritten = false;

	//Sets up inventory
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
	TickGas(DeltaTime);
	FlashlightBase->UpdateFlashlight(DeltaTime);
	RebreatherBase->UpdateRebreather(DeltaTime);
	UpdateMouseoverText();
}

void ADerelictCharacterBase::EquipItem(UToolBase* toolToEquip)
{
	//If an item is already equipped, hide it
	if (equippedItem)
		equippedItem->ToggleHolding();

	//If the player hit the equip key for the currently equipped item, remove it
	if (equippedItem && equippedItem->GetName() == toolToEquip->GetName())
		equippedItem = nullptr;
	//Else, equip the item for the key they did hit
	else
	{
		equippedItem = toolToEquip;
		equippedItem->ToggleHolding();
	}		
}

void ADerelictCharacterBase::EquipFlashlight()
{
	EquipItem(FlashlightBase);
}

void ADerelictCharacterBase::EquipRebreather()
{
	EquipItem(RebreatherBase);
}

void ADerelictCharacterBase::EquipBlowtorch()
{
	EquipItem(BlowtorchBase);
}

void ADerelictCharacterBase::Reload()
{
	ADerelictGameModeBase* gameMode = ((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode());
	if (!equippedItem)
		return;
	//If player has the reload item in inventory, reload the tool and remove one reload item
	if (inventory[equippedItem->ReloadItem] > 0)
	{
		equippedItem->Reload();
		inventory[equippedItem->ReloadItem]--;
	}
	else
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Need more " + gameMode->GetInventoryName(equippedItem->ReloadItem)));
}

void ADerelictCharacterBase::Action()
{
	if (equippedItem)
		equippedItem->Use();
}

void ADerelictCharacterBase::UpdateMouseoverText()
{
	AInteractable* result = raytrace();
	//If the raytrace hits an interactable object, set the mouseover text to that
	if (result)
	{
		result->UpdateMouseoverText();
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->SetMouseoverText(result->mouseOverText);
		mouseOverTextWritten = true;
	}
	//Else, set it to nothing
	else
	{
		if (mouseOverTextWritten)
			((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->SetMouseoverText(FText::FromString(""));
	}
}

void ADerelictCharacterBase::Interact()
{
	AInteractable* result = raytrace();
	if (result)
		result->Interact();
}

void ADerelictCharacterBase::OpenCrafting()
{
	Cast<ADerelictPlayerControllerBase>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->ToggleCraftingMenu();
}

AInteractable* ADerelictCharacterBase::raytrace()
{
	FHitResult hitActor(ForceInit);
	FVector CameraLoc;
	FRotator CameraRot;
	GetActorEyesViewPoint(CameraLoc, CameraRot);

	if (GetWorld()->LineTraceSingleByChannel(hitActor, CameraLoc, CameraLoc + (CameraRot.Vector() * 200), ECC_Pawn, FCollisionQueryParams(FName(TEXT("hitActor")), true, this)))
		return Cast<AInteractable>(hitActor.GetActor());
	else
		return nullptr;
}

void ADerelictCharacterBase::SetInGas(bool isInGas, float gasDPS)
{
   	this->isInGas = isInGas;
	this->gasDPS = gasDPS;
}

void ADerelictCharacterBase::TickGas(float deltaSeconds)
{
	if (isInGas && (equippedItem != RebreatherBase || !RebreatherBase->isOn))
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
	PlayerInputComponent->BindAction("OpenCrafting", IE_Pressed, this, &ADerelictCharacterBase::OpenCrafting);
}