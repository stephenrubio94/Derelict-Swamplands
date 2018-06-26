

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
	UpdateMouseoverText();
}
void ADoor::Interact()
{

}

void ADoor::UpdateMouseoverText()
{
	if (isLocked)
		mouseOverText = FText::FromString("E To Interact, Locked, ");
	else
		mouseOverText = FText::FromString("E To Interact, Unlocked, ");
	if (isAirtight)
		mouseOverText = FText::Format(mouseOverText, FText::FromString("sealed"));
	else
		mouseOverText = FText::Format(mouseOverText, FText::FromString("unsealed"));
	if (isBroken)
		mouseOverText = FText::Format(mouseOverText, FText::FromString("broken"));
}

bool ADoor::CanOpenDoor()
{
	if (isLocked)
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->SetMouseoverText(FText::FromString("Door Locked"));
		return false;
	}
	if (isBroken)
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->SetMouseoverText(FText::FromString("Door Broken"));
		return false;
	}
	return true;

}

void ADoor::Seal()
{
	isAirtight = true;
	//for (int x = 0; x < 2; x++)
	//	linkedGasBPs[0]->updateGasStatus();
}
