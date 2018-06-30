#include "DerelictGameModeBase.h"

ADerelictGameModeBase::ADerelictGameModeBase() : Super()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/DerelictCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	EInventoryName = { "Wiring Kit", "Battery", "Kerosene", "Air Filter" };
	ESubstationName = { "Air Filtration", "System Power", "Lights" };
}


void ADerelictGameModeBase::BeginPlay()
{
	//EInventoryName = { "Wiring Kit", "Battery", "Kerosene", "Air Filter" };
	//ESubstationName = { "Air Filtration", "System Power", "Lights" };
}

void ADerelictGameModeBase::SetMouseoverText(FText textToWrite)
{
	(Cast<UFPMainWidgetBase>(Cast<ADerelictPlayerControllerBase>(GetWorld()->GetFirstPlayerController())->mainWidget))->SetMouseOverText(textToWrite);
}

void ADerelictGameModeBase::SetMouseoverText(FString textToWrite)
{
	(Cast<UFPMainWidgetBase>(Cast<ADerelictPlayerControllerBase>(GetWorld()->GetFirstPlayerController())->mainWidget))->SetMouseOverText(FText::FromString(textToWrite));
}

void ADerelictGameModeBase::WriteToDisplay(FText textToWrite)
{
	(Cast<UFPMainWidgetBase>(Cast<ADerelictPlayerControllerBase>(GetWorld()->GetFirstPlayerController())->mainWidget))->WriteToHUD(textToWrite);
}

void ADerelictGameModeBase::WriteToDisplay(FString textToWrite)
{
	(Cast<UFPMainWidgetBase>(Cast<ADerelictPlayerControllerBase>(GetWorld()->GetFirstPlayerController())->mainWidget))->WriteToHUD(FText::FromString(textToWrite));
}

FString ADerelictGameModeBase::GetInventoryName(EInventory value)
{
	return EInventoryName[(int32)value];
}

FString ADerelictGameModeBase::GetSubstationName(ESubstation value)
{
	return ESubstationName[(int32)value];
}
