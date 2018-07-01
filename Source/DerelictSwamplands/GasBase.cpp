#include "GasBase.h"
#include "Door.h"
#include "Substation.h"

AGasBase::AGasBase()
{
	PrimaryActorTick.bCanEverTick = true;

	isDamagingPlayer = false;
	containsGas = false;
	DPS = 1;
	linkedDoors.Init(nullptr, 1);

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	Box->bGenerateOverlapEvents = true;
	Box->OnComponentBeginOverlap.AddDynamic(this, &AGasBase::TriggerEnter);
	RootComponent = Box;

	fog = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Fog"));
	fog->SetupAttachment(Box);
}

void AGasBase::BeginPlay()
{
	Super::BeginPlay();	
	UpdateGasStatus();
}

void AGasBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UpdateGasStatus();
}

void AGasBase::UpdateGasStatus()
{
	bool isRoomSealed = true;
	for (int x = 0; x < linkedDoors.Num(); x++ && isRoomSealed)
	{
		if (linkedDoors[x] != nullptr && !linkedDoors[x]->isAirtight)
		{
			isRoomSealed = false;
			if (linkedDoors[x]->linkedGasBPs[0]->containsGas || linkedDoors[x]->linkedGasBPs[1]->containsGas)
				containsGas = true;
		}
	}
	if (isRoomSealed && subsection->air->isWorking)
		containsGas = false;		
	fog->SetVisibility(containsGas);
}

void AGasBase::ChangeGas(bool containsGas)
{
	this->containsGas = containsGas;
}

void AGasBase::TriggerEnter(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<ADerelictCharacterBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)))
		Cast<ADerelictCharacterBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->SetInGas(containsGas, DPS);
}