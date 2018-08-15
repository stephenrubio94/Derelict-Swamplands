#include "CraftingWidgetBase.h"
#include "DerelictCharacterBase.h"
#include "DerelictGameModeBase.h"

//Initializes requiredItems by adding 0 of every item
UCraftingWidgetBase::UCraftingWidgetBase(const FObjectInitializer& ObjectInitializer) : UUserWidget(ObjectInitializer)
{
	TMap<EInventory, int> requiredItems;
	requiredItems.Add(EInventory::WiringKit, 1);
	requiredItems.Add(EInventory::Battery, 1);
	craftables.Add(Craftable(0, "Upgrade1", "Description", true, requiredItems));
	requiredItems.Reset();
	requiredItems.Add(EInventory::WiringKit, 2);
	requiredItems.Add(EInventory::Battery, 2);
	craftables.Add(Craftable(1, "Upgrade2", "Description", true, requiredItems));
	requiredItems.Reset();
	requiredItems.Add(EInventory::WiringKit, 3);
	requiredItems.Add(EInventory::Battery, 3);
	craftables.Add(Craftable(2, "Item1", "Description", false, requiredItems));
}

void UCraftingWidgetBase::CraftItem(int ID)
{
	craftables[ID].CraftItem();
}