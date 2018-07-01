#pragma once

#include "CoreMinimal.h"
#include "ToolBase.h"
#include "Door.h"
#include "Kismet/GameplayStatics.h"
#include "BlowtorchBase.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API UBlowtorchBase : public UToolBase
{
	GENERATED_BODY()	
protected:
	virtual void BeginPlay() override;
public:
	UBlowtorchBase();

	virtual void Use() override;
	virtual void Reload() override;
	virtual void ToggleHolding() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tool")
	bool isLoaded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
		class UStaticMeshComponent* blowtorchMesh;
};
