

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Subsection.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API ASubsection : public AActor
{
	GENERATED_BODY()
	
public:	
	class ASubstation* power;
	class ASubstation* air;
	class ASubstation* lights;
	
};
