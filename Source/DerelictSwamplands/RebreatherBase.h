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

	virtual void Use() override;
	virtual void Reload() override;
	virtual void ToggleHolding() override;
	void UpdateRebreather(float deltaSeconds);

	//Percent durability the filter has left.  When it hits 0, it no longer filters out air.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	float filterDurability;
	//Rate of durability removed per tick
	float drainRate;
	bool isOn;
	bool lowFilterDisplayed;
};
