#include "Substation.h"
#include "DerelictCharacterBase.h"
#include "Kismet/GameplayStatics.h"

ASubstation::ASubstation()
{
	isWorking = false;
}

void ASubstation::BeginPlay()
{
	player = Cast<ADerelictCharacterBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void ASubstation::Interact()
{
	//Exits if system is already working
	if (isWorking)
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("System Working"));
		return;
	}

	//If player has a wiring kit, restore power
	if (player->inventory[EInventory::WiringKit] > 0)
	{
		//If type is system power, restore it, and update all gas volumes to see if they can be filtered out
		if (type == ESubstation::SystemPower)
		{
			isWorking = true;
			player->inventory[EInventory::WiringKit]--;
			((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("System Repaired"));
			subsection->UpdateAllGas();
		}
		else
		{
			//System power is required to restore any other system.  Checks for that.
			if (subsection->power->isWorking)
			{
				isWorking = true;
				player->inventory[EInventory::WiringKit]--;
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

void ASubstation::UpdateMouseoverText()
{
	if (!isWorking)
		mouseOverText = FText::FromString(((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->GetSubstationName(type) + ", use wiring kit to repair");
	else
		mouseOverText = FText::FromString(((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->GetSubstationName(type) + ", working");
}
