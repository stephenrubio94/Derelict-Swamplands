#include "BlowtorchBase.h"
#include "Kismet/GameplayStatics.h"

UBlowtorchBase::UBlowtorchBase()
{
	isLoaded = false;
	ReloadItem = EInventoryItemEnum::Kerosene;
}

void UBlowtorchBase::BeginPlay()
{
	Super::BeginPlay();
}

void UBlowtorchBase::Use()
{
	if (isLoaded)
	{
		//Play sparks animation
		ADoor* result = Cast<ADoor>(Cast<ADerelictCharacterBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->raytrace());
		//If Cast fails
		if (result->isAirtight)
		{
			((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->SetMouseoverText(FText::FromString("Door Already Airtight"));
		}
		else
		{
			result->Seal();
			isLoaded = false;
		}
	}
	else
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->SetMouseoverText(FText::FromString("Blowtorch needs kerosene"));
	}
}

void UBlowtorchBase::Reload()
{
	Super::Reload();
	if (isLoaded)
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->SetMouseoverText(FText::FromString("Blowtorch already has kerosene"));
	}
	else
	{
		isLoaded = true;
	}
}

void UBlowtorchBase::ToggleHolding()
{
	Super::ToggleHolding();
}
