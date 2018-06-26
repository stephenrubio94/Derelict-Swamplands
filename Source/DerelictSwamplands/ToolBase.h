#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DerelictGameModeBase.h"
#include "ToolBase.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API UToolBase : public USceneComponent
{
	GENERATED_BODY()
	
public:	
	UToolBase();

protected:
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable, Category = "Tool")
	virtual void Use();	
	UFUNCTION(BlueprintCallable, Category = "Tool")
	virtual void Reload();
	UFUNCTION(BlueprintCallable, Category = "Tool")
	virtual void ToggleHolding();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tool")
	EInventory ReloadItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tool")
	class USceneComponent* RootItem;	
};
