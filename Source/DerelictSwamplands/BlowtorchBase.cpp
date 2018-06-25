

#include "BlowtorchBase.h"

ABlowtorchBase::ABlowtorchBase()
{
	isLoaded = false;
	ReloadItem = EInventoryItemEnum::Kerosene;
}

void ABlowtorchBase::BeginPlay()
{
	Super::BeginPlay();
}

void ABlowtorchBase::Use()
{
	if (isLoaded)
	{
		////Play sparks animation
		////Raytrace
		////Cast to door
		//if (door.isAirtight)
		//{
		//	//Write to HUD: Door Already Airtight
		//}
		//else
		//{
		//	door.Seal();
		//	loaded = false;
		//}
	}
	else
	{
		//Write to HUD: Blowtorch needs kerosene
	}
}

void ABlowtorchBase::Reload()
{
	Super::Reload();
	if (isLoaded)
	{
		//Write to HUD: Blowtorch already has kerosene
	}
	else
	{
		isLoaded = true;
	}
}

void ABlowtorchBase::ToggleHolding()
{
	Super::ToggleHolding();
}
