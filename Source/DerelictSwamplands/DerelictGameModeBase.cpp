#include "DerelictGameModeBase.h"

ADerelictGameModeBase::ADerelictGameModeBase() : Super()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/DerelictCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}

void ADerelictGameModeBase::BeginPlay()
{

}

void ADerelictGameModeBase::SetMouseoverText(FText textToWrite)
{
	UFPMainWidgetBase* myWidget = Cast<UFPMainWidgetBase>(Cast<ADerelictPlayerControllerBase>(GetWorld()->GetFirstPlayerController())->mainWidget);
	myWidget->SetMouseOverText(textToWrite);
}

void ADerelictGameModeBase::WriteToDisplay(FText textToWrite)
{
	UFPMainWidgetBase* myWidget = Cast<UFPMainWidgetBase>(Cast<ADerelictPlayerControllerBase>(GetWorld()->GetFirstPlayerController())->mainWidget);
	myWidget->WriteToHUD(textToWrite);
}
