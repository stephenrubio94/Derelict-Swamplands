#include "Interactable.h"

AInteractable::AInteractable()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	mouseOverText = FText::AsCultureInvariant("Press E to Interact");
}

void AInteractable::BeginPlay()
{
	gameMode = (ADerelictGameModeBase*)GetWorld()->GetAuthGameMode();
}

void AInteractable::UpdateMouseoverText()
{
}

void AInteractable::Interact()
{
}

