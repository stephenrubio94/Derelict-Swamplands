

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DerelictGameModeBase.h"
#include "PlayerTool.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DERELICTSWAMPLANDS_API UPlayerTool : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerTool();


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
};
