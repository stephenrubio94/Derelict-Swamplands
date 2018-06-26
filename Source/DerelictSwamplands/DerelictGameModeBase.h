#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UObject/ConstructorHelpers.h"
#include "DerelictGameModeBase.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EInventoryItemEnum : uint8
{
	WiringKit 	UMETA(DisplayName = "Wiring Kit"),
	Battery 	UMETA(DisplayName = "Battery"),
	Kerosene 	UMETA(DisplayName = "Kerosene"),
	AirFilter	UMETA(DisplayName = "AirFilter")
};

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ESubstation : uint8
{
	AirFiltration 	UMETA(DisplayName = "Air Filtration"),
	SystemPower 	UMETA(DisplayName = "System Power"),
	Lights 	UMETA(DisplayName = "Lights")
};

UCLASS()
class DERELICTSWAMPLANDS_API ADerelictGameModeBase : public AGameModeBase
{
	GENERATED_BODY()	
public:
	ADerelictGameModeBase();
	void SetMouseoverText(FText textToWrite);
	void WriteToDisplay(FText textToWrite);
protected:
	virtual void BeginPlay() override;
};
