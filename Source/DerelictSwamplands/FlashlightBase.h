#pragma once

#include "CoreMinimal.h"
#include "ToolBase.h"
#include "Components/SpotLightComponent.h"
#include "FlashlightBase.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API AFlashlightBase : public AToolBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	AFlashlightBase();

	UFUNCTION(BlueprintCallable, Category = "Tool")
	virtual void Use() override;
	UFUNCTION(BlueprintCallable, Category = "Tool")
	virtual void Reload() override;
	UFUNCTION(BlueprintCallable, Category = "Tool")
	virtual void ToggleHolding() override;
	UFUNCTION(BlueprintCallable, Category = "Light")
	void UpdateFlashlight(float deltaSeconds);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light")
	float maxIntensity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battery")
	float battery;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battery")
	float drainRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light")
	bool isOn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battery")
	bool lowBatteryDisplayed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light")
	class USpotLightComponent* light;
};
