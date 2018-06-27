

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Subsection.generated.h"


UCLASS()
class DERELICTSWAMPLANDS_API ASubsection : public AActor
{
	GENERATED_BODY()
protected:
	//virtual void Tick(float DeltaTime) override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	class ASubstation* power;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	class ASubstation* air;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	class ASubstation* lights;
};
