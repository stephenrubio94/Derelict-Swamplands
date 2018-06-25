#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DerelictGameModeBase.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EInventoryItemEnum : uint8
{
	WiringKit 	UMETA(DisplayName = "Wiring Kit"),
	Battery 	UMETA(DisplayName = "Battery"),
	Kerosene 	UMETA(DisplayName = "Kerosene"),
	AirFilter	UMETA(DisplayName = "AirFilter")
};

UCLASS()
class DERELICTSWAMPLANDS_API ADerelictGameModeBase : public AGameModeBase
{
	GENERATED_BODY()	
};
