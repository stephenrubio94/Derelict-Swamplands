#include "Substation.h"
#include "DerelictCharacterBase.h"
#include "Kismet/GameplayStatics.h"

ASubstation::ASubstation()
{
	isWorking = false;
}

void ASubstation::BeginPlay()
{
	mouseOverText = FText::FromString("Use Wiring Kit to Repair");
	player = Cast<ADerelictCharacterBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void ASubstation::Interact()
{
	if (isWorking)
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("System Working"));
		return;
	}

	if (player->inventory[EInventory::WiringKit] > 0)
	{
		if (type == ESubstation::SystemPower)
		{
			isWorking = true;
			player->inventory[EInventory::WiringKit]--;
			mouseOverText = FText::FromString("Working");
			((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("System Repaired"));
			subsection->UpdateAllGas();
		}
		else
		{
			if (subsection->power->isWorking)
			{
				isWorking = true;
				mouseOverText = FText::FromString("Working");
				((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("System Repaired"));
				subsection->UpdateAllGas();
			}
			else
				((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Primary System Needs Power"));
		}
	}
	else
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Wiring Kit Required"));
}