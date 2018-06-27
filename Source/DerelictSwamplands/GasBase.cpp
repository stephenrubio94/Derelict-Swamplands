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
	RootComponent = Box;
	Box->OnComponentBeginOverlap.AddDynamic(this, &AGasBase::TriggerEnter);
	Box->OnComponentEndOverlap.AddDynamic(this, &AGasBase::TriggerExit);

	//fog->AttachToComponent(RootComponent);
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
	for (int x = 0; x < linkedDoors.Num(); x++)
	{
		//TODO Bug, if any door is not airtight, gas spreads to all linkedGasBPs
		if (linkedDoors[x] != nullptr && !linkedDoors[x]->isAirtight)
		{
			isRoomSealed = false;
			for (int y = 0; y < linkedDoors[x]->linkedGasBPs.Num(); y++)
			{
				if (linkedDoors[x]->linkedGasBPs[y]->containsGas)
					containsGas = true;
			}
			break;
		}
	}
	if (isRoomSealed && subsection->air->isWorking)
		containsGas = false;		
	//fog->SetActorHiddenInGame(containsGas);
}

void AGasBase::ChangeGas(bool containsGas)
{
	this->containsGas = containsGas;
}

void AGasBase::TriggerEnter(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (containsGas)
		Cast<ADerelictCharacterBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->SetInGas(true, DPS);
}

void AGasBase::TriggerExit(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (containsGas)
		Cast<ADerelictCharacterBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->SetInGas(false, 0);
}
