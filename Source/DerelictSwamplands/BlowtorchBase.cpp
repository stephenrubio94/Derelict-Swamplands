#include "BlowtorchBase.h"

UBlowtorchBase::UBlowtorchBase()
{
	isLoaded = false;
	ReloadItem = EInventory::Kerosene;
	blowtorchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	niceName = FText::FromString("Blowtorch");
	HUDAmmoText = FText::FromString("Kerosene: Not Loaded");
}

void UBlowtorchBase::BeginPlay()
{
	Super::BeginPlay();
}

void UBlowtorchBase::Use()
{
	if (isLoaded)
	{
		//Play sparks animation
		ADoor* result = Cast<ADoor>(Cast<ADerelictCharacterBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->raytrace());
		if (!result)
			return;
		if (result->isAirtight)
			((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Door Already Airtight"));
		else
		{
			((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Door Sealed"));
			result->Seal();
			isLoaded = false;
			HUDAmmoText = FText::FromString("Kerosene: Not Loaded");
		}
	}
	else
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Blowtorch needs kerosene"));
	}
}

void UBlowtorchBase::Reload()
{
	Super::Reload();
	if (isLoaded)
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Blowtorch already has kerosene"));
	}
	else
	{
		isLoaded = true;
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Kerosene loaded"));
		HUDAmmoText = FText::FromString("Kerosene: Loaded");
	}
}

void UBlowtorchBase::ToggleHolding()
{
	Super::ToggleHolding();
}
