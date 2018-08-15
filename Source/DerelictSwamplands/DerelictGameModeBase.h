#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Subsection.h"
#include "DerelictGameModeBase.generated.h"

//Inventory item enum
UENUM(BlueprintType)
enum class EInventory : uint8
{
	WiringKit 	UMETA(DisplayName = "Wiring Kit"),
	Battery 	UMETA(DisplayName = "Battery"),
	Kerosene 	UMETA(DisplayName = "Kerosene"),
	AirFilter	UMETA(DisplayName = "AirFilter")
};

//Substation type enum
UENUM(BlueprintType)
enum class ESubstation : uint8
{
	AirFiltration 	UMETA(DisplayName = "Air Filtration"),
	SystemPower 	UMETA(DisplayName = "System Power"),
	Lights 			UMETA(DisplayName = "Lights")
};

UCLASS()
class DERELICTSWAMPLANDS_API ADerelictGameModeBase : public AGameModeBase
{
	GENERATED_BODY()	
public:
	ADerelictGameModeBase();
	void SetMouseoverText(FText textToWrite);
	void SetMouseoverText(FString textToWrite);
	//Writes text to HUD
	void WriteToDisplay(FText textToWrite);
	void WriteToDisplay(FString textToWrite);
	//List of all subsections
	TArray<ASubsection*> subsections;
	//String array to get names of enums
	TArray<FString> EInventoryName;
	TArray<FString> ESubstationName;
	FString GetInventoryName(EInventory value);
	FString GetSubstationName(ESubstation value);
};
