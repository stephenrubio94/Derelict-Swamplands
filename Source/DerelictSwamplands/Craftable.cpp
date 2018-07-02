#include "Craftable.h"
#include "Kismet/GameplayStatics.h"

Craftable::Craftable(int id, FString name, FString description, bool isUpgrade, TMap<EInventory, int> requiredItems)
{
	this->ID = ID;
	this->name = name;
	this->description = description;
	this->isUpgrade = isUpgrade;
	this->requiredItems = requiredItems;
}

void Craftable::Craft()
{
	if (HaveMaterials())
	{
		for (int x = 0; x<requiredItems.Num(); x++)

			if (isUpgrade)
				CraftUpgrade();
			else
				CraftItem();
	}
}

void Craftable::CraftItem()
{
}

bool Craftable::HaveMaterials()
{
	return false;
}

void Craftable::CraftUpgrade()
{
}
