#pragma once

#include "CoreMinimal.h"
#include "ToolBase.h"
#include "RebreatherBase.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API URebreatherBase : public UToolBase
{
	GENERATED_BODY()
public:
	URebreatherBase();	

	UFUNCTION(BlueprintCallable, Category = "Tool")
		virtual void Use() override;
	UFUNCTION(BlueprintCallable, Category = "Tool")
		virtual void Reload() override;
	UFUNCTION(BlueprintCallable, Category = "Tool")
		virtual void ToggleHolding() override;
	UFUNCTION(BlueprintCallable, Category = "Light")
		void UpdateRebreather(float deltaSeconds);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battery")
		float filterDurability;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battery")
		float drainRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light")
		bool isOn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battery")
		bool lowFilterDisplayed;
};
