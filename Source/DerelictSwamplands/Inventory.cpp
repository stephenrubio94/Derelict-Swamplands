
#include "Inventory.h"

Inventory::Inventory()
{
	inventoryData.Add(EInventory::WiringKit, 1);
	int test = inventoryData[EInventory::WiringKit];
	inventoryData[EInventory::WiringKit] = 2;
}