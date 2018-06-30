#include "ToolBase.h"

void UToolBase::BeginPlay()
{
	Super::BeginPlay();
	ToggleVisibility(true);
}

void UToolBase::Use() {}

void UToolBase::Reload() {}

void UToolBase::ToggleHolding()
{
	ToggleVisibility(true);
}

