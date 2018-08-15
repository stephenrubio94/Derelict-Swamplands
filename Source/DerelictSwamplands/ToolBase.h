#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "DerelictGameModeBase.h"
#include "Components/ActorComponent.h"
#include "ToolBase.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DERELICTSWAMPLANDS_API UToolBase : public UActorComponent
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Use();	
	virtual void Reload();
	virtual void ToggleHolding();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		EInventory ReloadItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	FText niceName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	FText HUDAmmoText;
};
