#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "DerelictGameModeBase.h"
#include "ToolBase.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DERELICTSWAMPLANDS_API UToolBase : public USceneComponent
{
	GENERATED_BODY()
	
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		FText niceName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		FText HUDAmmoText;
};
