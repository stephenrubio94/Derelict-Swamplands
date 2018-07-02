#include "Interactable.h"

void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	gameMode = (ADerelictGameModeBase*)GetWorld()->GetAuthGameMode();
}

AInteractable::AInteractable()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	mouseOverText = FText::AsCultureInvariant("Press 'E' to Interact");
}

void AInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractable::UpdateMouseoverText()
{
}

void AInteractable::Interact()
{
}

