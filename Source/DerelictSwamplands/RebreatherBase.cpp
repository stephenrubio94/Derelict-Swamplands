#include "RebreatherBase.h"

URebreatherBase::URebreatherBase() : UToolBase()
{
	filterDurability = 100;
	drainRate = 1;
	isOn = false;
	lowFilterDisplayed = false;
	ReloadItem = EInventory::AirFilter;
	HUDAmmoText = FText::FromString("Air Filter: " + FString::FromInt((int)filterDurability));
	niceName = FText::FromString("Rebreather");

	rebreatherMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RebreatherMesh"));
	rebreatherMesh->SetupAttachment(this);
}

void URebreatherBase::Use()
{
	Super::Use();
	if (isOn)
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Rebreather removed"));
	else
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Rebreather equiped"));
	isOn = !isOn;
}

void URebreatherBase::Reload()
{
	Super::Reload();
	if (filterDurability < 90)
	{
		lowFilterDisplayed = false;
		if (filterDurability >= 25)
			filterDurability = 100;
		else
			filterDurability += 75;
	}
	else
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Filter in good condition"));
	}
}

void URebreatherBase::ToggleHolding()
{
	Super::ToggleHolding();
	isOn = false;
}

void URebreatherBase::UpdateRebreather(float deltaSeconds)
{
	if (!isOn || filterDurability <= 0)
		return;
	if (filterDurability < 10 && !lowFilterDisplayed)
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Need new filter"));
		lowFilterDisplayed = true;
	}
	filterDurability -= drainRate * deltaSeconds;
	HUDAmmoText = FText::FromString("Air Filter: " + FString::FromInt((int)filterDurability));
}