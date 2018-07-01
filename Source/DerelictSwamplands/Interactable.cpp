#include "Interactable.h"

AInteractable::AInteractable()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	mouseOverText = FText::AsCultureInvariant("Press E to Interact");
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

