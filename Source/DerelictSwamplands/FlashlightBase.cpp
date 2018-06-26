#include "FlashlightBase.h"

float maxIntensity;
float battery;
float drainRate;
bool isOn;
bool lowBatteryDisplayed;

UFlashlightBase::UFlashlightBase()
{
	maxIntensity = 6000;
	battery = 100;
	drainRate = 1;
	isOn = false;
	lowBatteryDisplayed = false;
	light = CreateDefaultSubobject<USpotLightComponent>(TEXT("light"));
	light->Intensity = 0.0f;
	RootItem = light;
	ReloadItem = EInventoryItemEnum::Battery;
}

void UFlashlightBase::BeginPlay()
{
	Super::BeginPlay();
}

void UFlashlightBase::Use()
{
	UE_LOG(LogTemp, Warning, TEXT("FlashlightBase use"));

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
		//Print to HUD: Battery nearly full
	}
}

void UFlashlightBase::ToggleHolding()
{
	Super::ToggleHolding();
	light->ULightComponent::SetIntensity(0);
	isOn = false;
}

void UFlashlightBase::UpdateFlashlight(float deltaSeconds)
{
	if (!isOn || battery <= 0)
		return;
	if (battery < 10 && !lowBatteryDisplayed)
	{
		//Print to HUD: Need new battery
		lowBatteryDisplayed = true;
	}
	battery -= drainRate * deltaSeconds;
	light->ULightComponent::SetIntensity(maxIntensity*battery);
}
