#include "ToolBase.h"

// Sets default values
UToolBase::UToolBase()
{
	RootItem = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
}

// Called when the game starts or when spawned
void UToolBase::BeginPlay()
{
	Super::BeginPlay();
	RootItem->USceneComponent::ToggleVisibility(true);
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
	RootItem->USceneComponent::ToggleVisibility(true);
}

