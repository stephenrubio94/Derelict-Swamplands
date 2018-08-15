#include "PlayerTool.h"

UPlayerTool::UPlayerTool()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UPlayerTool::BeginPlay()
{
	Super::BeginPlay();
	ToggleVisibility(true);	
}

//// Called every frame
//void UPlayerTool::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

void UPlayerTool::Use() {}

void UPlayerTool::Reload() {}

void UPlayerTool::ToggleHolding()
{
	ToggleVisibility(true);
}

