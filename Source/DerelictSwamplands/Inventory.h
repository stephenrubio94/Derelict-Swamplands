#pragma once

#include "CoreMinimal.h"
#include "DerelictGamemodeBase.h"

class DERELICTSWAMPLANDS_API Inventory
{
public:
	Inventory();
	TMap<EInventory, int> inventoryData;
};
