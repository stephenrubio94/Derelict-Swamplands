

#include "PlayerTool.h"


// Sets default values for this component's properties
UPlayerTool::UPlayerTool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
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

void UPlayerTool::Use()
{
	UE_LOG(LogTemp, Warning, TEXT("Super use"));
}

void UPlayerTool::Reload()
{
	UE_LOG(LogTemp, Warning, TEXT("Super reload"));
}

void UPlayerTool::ToggleHolding()
{
	ToggleVisibility(true);
}

