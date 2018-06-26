#pragma once

#include "CoreMinimal.h"
#include "DerelictGamemodeBase.h"

class DERELICTSWAMPLANDS_API Inventory
{
public:
	Inventory();
	TMap<EInventoryItemEnum, int> inventoryData;
};
