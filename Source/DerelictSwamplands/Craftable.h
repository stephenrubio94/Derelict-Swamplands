

#pragma once
#pragma once
#include "CoreMinimal.h"
#include "DerelictGameModeBase.h"

class DERELICTSWAMPLANDS_API Craftable
{
public:
	Craftable(int ID, FString name, FString description, bool isUpgrade, TMap<EInventory, int> requiredItems);
	int ID;
	FString name;
	FString description;
	bool isUpgrade;
	TMap<EInventory, int> requiredItems;

	void Craft();
	void CraftItem();
	bool HaveMaterials();
	void CraftUpgrade();
};
