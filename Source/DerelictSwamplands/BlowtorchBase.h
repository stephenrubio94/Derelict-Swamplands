#pragma once

#include "CoreMinimal.h"
#include "ToolBase.h"
#include "Door.h"
#include "BlowtorchBase.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API UBlowtorchBase : public UToolBase
{
	GENERATED_BODY()	
protected:
	virtual void BeginPlay() override;
public:
	UBlowtorchBase();

	UFUNCTION(BlueprintCallable, Category = "Tool")
	virtual void Use() override;
	UFUNCTION(BlueprintCallable, Category = "Tool")
	virtual void Reload() override;
	UFUNCTION(BlueprintCallable, Category = "Tool")
	virtual void ToggleHolding() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tool")
	bool isLoaded;
};
