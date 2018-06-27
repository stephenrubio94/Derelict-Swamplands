#include "Interactable.h"

AInteractable::AInteractable()
{
	PrimaryActorTick.bCanEverTick = true;
	RootItem = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = RootItem;
	mouseOverText = FText::AsCultureInvariant("Press E to Interact");
}

void AInteractable::UpdateMouseoverText()
{
}

void AInteractable::Interact()
{
}

