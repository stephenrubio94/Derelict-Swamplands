#include "Substation.h"

ASubstation::ASubstation()
{
	isWorking = false;
}

void ASubstation::BeginPlay()
{
	//mouseoverText = type.toString() + "\nUse Wiring Kit to Repair";
}

void ASubstation::Interact()
{
	if (isWorking)
	{
		//Message: system repaired
		return;
	}

	//if (playerCharacter.inventoryObject[EInventoryEnum::WiringKit] > 0)
	//{
	//	if (type.toString() == "SystemPower")
	//	{
	//		isWorking = true;
	//		playerCharacter.inventoryObject[EInventoryEnum::WiringKit]--;
	//		mouseOverText = type.toString() + "\nWorking";
	//		//Write: Repaired
	//	}
	//	else
	//	{
	//		//if System Power repaired
	//		//{
	//		////repair it
	//		//	mouseOverText = type.toString() + "\nWorking";
	//		//	//Write: Repaired
	//		//}

	//		//else
	//			//Write: Error: repair system power
	//	}
	//}
	//else
	//{
	//	//Write to HUD: Wiring Kit Required
	//}
}