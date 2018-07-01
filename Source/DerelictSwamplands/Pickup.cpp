#include "Pickup.h"
#include "Kismet/GameplayStatics.h"

APickup::APickup()
{
	mouseOverText = FText::FromString("");
}

void APickup::UpdateMouseoverText()
{
	if (mouseOverText.EqualTo(FText::FromString("")))
		mouseOverText = FText::FromString(gameMode->GetInventoryName(itemType) + ", 'E' To Pickup");
}

void APickup::Interact()
{
	Cast<ADerelictCharacterBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->inventory[itemType]++;
	gameMode->WriteToDisplay(gameMode->GetInventoryName(itemType) + " picked up");
	UGameplayStatics::PlaySoundAtLocation(this, PickupSound, GetActorLocation());
	this->Destroy();
}



