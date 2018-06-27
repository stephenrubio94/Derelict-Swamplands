#include "Door.h"
#include "GasBase.h"

ADoor::ADoor()
{
	isLocked = false;
	isAirtight = true;
	isBroken = false;
	linkedGasBPs.Init(nullptr, 2);
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
	UpdateMouseoverText();
}
void ADoor::Interact()
{
	if (!CanOpenDoor())
	{
		//Play locked sound
	}
	else
		BPOpenDoor();
}

void ADoor::UpdateMouseoverText()
{
	FString newMouseOverText;
	if (isLocked)
		newMouseOverText = "E To Interact, Locked";
	else
		newMouseOverText = "E To Interact, Unlocked";
	if (isAirtight)
		newMouseOverText += ", Sealed";
	else
		newMouseOverText += ", Unsealed";
	if (isBroken)
		newMouseOverText += ", Broken";

	mouseOverText = FText::AsCultureInvariant(newMouseOverText);
}

bool ADoor::CanOpenDoor()
{
	if (isLocked)
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Door Locked"));
		return false;
	}
	if (isBroken)
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Door Broken"));
		return false;
	}
	return true;
}

void ADoor::Seal()
{
	isAirtight = true;
	for (int x = 0; x < 2; x++)
		linkedGasBPs[x]->UpdateGasStatus();
}
