#include "ToolBase.h"

// Sets default values
AToolBase::AToolBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootItem = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = RootItem;
}

// Called when the game starts or when spawned
void AToolBase::BeginPlay()
{
	Super::BeginPlay();
	RootComponent->USceneComponent::ToggleVisibility(true);
}

// Called every frame
void AToolBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AToolBase::Use()
{
	UE_LOG(LogTemp, Warning, TEXT("Super use"));
}

void AToolBase::Reload()
{
	UE_LOG(LogTemp, Warning, TEXT("Super reload"));
}

void AToolBase::ToggleHolding()
{
	RootComponent->USceneComponent::ToggleVisibility(true);
}

