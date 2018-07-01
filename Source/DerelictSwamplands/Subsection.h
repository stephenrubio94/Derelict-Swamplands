

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Subsection.generated.h"


UCLASS()
class DERELICTSWAMPLANDS_API ASubsection : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		class ASubstation* power;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		class ASubstation* air;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
		class ASubstation* lights;
	void UpdateAllGas();
};
