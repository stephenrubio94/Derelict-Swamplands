#include "Pickup.h"
#include "Kismet/GameplayStatics.h"


void APickup::Interact()
{
	ADerelictCharacterBase* player = Cast<ADerelictCharacterBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	player->inventory[itemType]++;
	//TODO: Play pickup sound
	((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->SetMouseoverText(FText::FromString(/*todo show item name*/" picked up"));
	this->Destroy();
}



