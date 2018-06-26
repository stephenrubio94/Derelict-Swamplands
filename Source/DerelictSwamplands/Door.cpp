

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
		newMouseOverText = "E To Interact, Locked, ";
	else
		newMouseOverText = "E To Interact, Unlocked, ";
	if (isAirtight)
		newMouseOverText = "sealed";
	else
		newMouseOverText = "unsealed";
	if (isBroken)
		newMouseOverText = "broken";

	mouseOverText = FText::AsCultureInvariant(newMouseOverText);
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
