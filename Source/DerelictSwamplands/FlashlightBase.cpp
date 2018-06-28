#include "FlashlightBase.h"

float maxIntensity;
float battery;
float drainRate;
bool isOn;
bool lowBatteryDisplayed;

UFlashlightBase::UFlashlightBase() : UToolBase()
{
	maxIntensity = 6000;
	battery = 100;
	drainRate = 1;
	isOn = false;
	lowBatteryDisplayed = false;
	light = CreateDefaultSubobject<USpotLightComponent>(TEXT("Light"));
	light->Intensity = 0.0f;
	light->SetLightColor(FColor(120,120,25));
	light->SetupAttachment(this);
	ReloadItem = EInventory::Battery;
	niceName = FText::FromString("Flashlight");
}

void UFlashlightBase::Use()
{
	Super::Use();

	if (isOn)
	{
		light->ULightComponent::SetIntensity(0);
		isOn = false;
	}
	else
	{
		light->ULightComponent::SetIntensity(maxIntensity);
		isOn = true;
	}
}

void UFlashlightBase::Reload()
{
	Super::Reload();
	if (battery < 90)
	{
		lowBatteryDisplayed = false;
		if (battery >= 25)
			battery = 100;
		else
			battery += 75;
	}
	else
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Battery nearly full"));
	}
}

void UFlashlightBase::ToggleHolding()
{
	Super::ToggleHolding();
	light->ULightComponent::SetIntensity(0);
	isOn = false;
}

//Run every tick
void UFlashlightBase::UpdateFlashlight(float deltaSeconds)
{
	if (!isOn || battery <= 0)
		return;
	if (battery < 10 && !lowBatteryDisplayed)
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Need new battery"));
		lowBatteryDisplayed = true;
	}
	battery -= drainRate * deltaSeconds;
	light->ULightComponent::SetIntensity(maxIntensity*battery);
}