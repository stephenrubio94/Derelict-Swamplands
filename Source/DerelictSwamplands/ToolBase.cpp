#include "ToolBase.h"

void UToolBase::BeginPlay()
{
	Super::BeginPlay();
	ToggleVisibility(true);
}

void UToolBase::Use()
{
	UE_LOG(LogTemp, Warning, TEXT("Super use"));
}

void UToolBase::Reload()
{
	UE_LOG(LogTemp, Warning, TEXT("Super reload"));
}

void UToolBase::ToggleHolding()
{
	ToggleVisibility(true);
}

