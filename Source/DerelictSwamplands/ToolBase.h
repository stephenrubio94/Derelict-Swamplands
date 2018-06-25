#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DerelictGameModeBase.h"
#include "ToolBase.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API AToolBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AToolBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Tool")
	virtual void Use();	
	UFUNCTION(BlueprintCallable, Category = "Tool")
	virtual void Reload();
	UFUNCTION(BlueprintCallable, Category = "Tool")
	virtual void ToggleHolding();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tool")
	EInventoryItemEnum ReloadItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tool")
	class USceneComponent* RootItem;
};
