#pragma once

#include "CoreMinimal.h"
#include "ToolBase.h"
#include "BlowtorchBase.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API ABlowtorchBase : public AToolBase
{
	GENERATED_BODY()	
protected:
	virtual void BeginPlay() override;
public:
	ABlowtorchBase();

	UFUNCTION(BlueprintCallable, Category = "Tool")
	virtual void Use() override;
	UFUNCTION(BlueprintCallable, Category = "Tool")
	virtual void Reload() override;
	UFUNCTION(BlueprintCallable, Category = "Tool")
	virtual void ToggleHolding() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tool")
	bool isLoaded;
};
