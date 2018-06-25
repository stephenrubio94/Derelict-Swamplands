

#include "Door.h"

// Sets default values
ADoor::ADoor()
{
	isLocked = false;
	isAirtight = true;
	isBroken = false;
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
}
void ADoor::Interact()
{

}

void ADoor::UpdateMouseoverText()
{
}

void ADoor::Seal()
{
}
