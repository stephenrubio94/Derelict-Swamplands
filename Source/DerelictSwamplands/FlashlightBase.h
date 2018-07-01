#pragma once

#include "CoreMinimal.h"
#include "ToolBase.h"
#include "Components/SpotLightComponent.h"
#include "FlashlightBase.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API UFlashlightBase : public UToolBase
{
	GENERATED_BODY()
protected:
	//virtual void BeginPlay() override;
public:
	UFlashlightBase();

	virtual void Use() override;
	virtual void Reload() override;
	virtual void ToggleHolding() override;
	void UpdateFlashlight(float deltaSeconds);

	float maxIntensity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battery")
	float battery;
	float drainRate;
	bool isOn;
	bool lowBatteryDisplayed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light")
	USpotLightComponent* light;
};
