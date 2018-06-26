
#include "Inventory.h"

Inventory::Inventory()
{
	inventoryData.Add(EInventoryItemEnum::WiringKit, 1);
	int test = inventoryData[EInventoryItemEnum::WiringKit];
	inventoryData[EInventoryItemEnum::WiringKit] = 2;
}