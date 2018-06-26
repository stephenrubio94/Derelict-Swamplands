#include "GasBase.h"

AGasBase::AGasBase()
{
	PrimaryActorTick.bCanEverTick = true;

	isDamagingPlayer = false;
	bool containsGas = false;
	dps = 1;
	isRoomSealed = false;
	linkedDoors.Init(nullptr, 2);
}

void AGasBase::BeginPlay()
{
	Super::BeginPlay();	
}

void AGasBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateGasStatus();
}

void AGasBase::UpdateGasStatus()
{
	//TODO Implement
}

void AGasBase::ChangeGas()
{
	//TODO Implement
}

