#include "Substation.h"

ASubstation::ASubstation()
{
	isWorking = false;
	//TODO player reference broken
	player = Cast<ADerelictCharacterBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void ASubstation::BeginPlay()
{
	mouseOverText = FText::FromString("Use Wiring Kit to Repair");
}

void ASubstation::Interact()
{
	if (isWorking)
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->SetMouseoverText(FText::FromString("System Working"));
		return;
	}

	if (player->inventory[EInventory::WiringKit] > 0)
	{
		if (type == ESubstation::SystemPower)
		{
			isWorking = true;
			player->inventory[EInventory::WiringKit]--;
			mouseOverText = FText::FromString("Working");
			((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->SetMouseoverText(FText::FromString("System Repaired"));
		}
		else
		{
			if (subsection->power->isWorking)
			{
				isWorking = true;
				mouseOverText = FText::FromString("Working");
				((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->SetMouseoverText(FText::FromString("System Repaired"));
			}
			else
				((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->SetMouseoverText(FText::FromString("Primary System Needs Power"));
		}
	}
	else
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->SetMouseoverText(FText::FromString("Wiring Kit Required"));
}