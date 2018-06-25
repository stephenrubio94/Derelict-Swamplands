

#include "DerelictCharacterBase.h"


// Sets default values
ADerelictCharacterBase::ADerelictCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADerelictCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADerelictCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADerelictCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

