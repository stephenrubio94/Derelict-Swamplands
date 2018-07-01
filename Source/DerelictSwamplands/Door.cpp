#include "Door.h"
#include "GasBase.h"

ADoor::ADoor()
{
	isLocked = false;
	isAirtight = true;
	isBroken = false;
	isOpen = false;
	doorOpen = FVector(115, 0, -142);
	doorClosed = FVector(0, 0, -142);
	linkedGasBPs.Init(nullptr, 2);

	doorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	doorMesh->SetupAttachment(RootComponent);
	doorMesh->SetRelativeLocation(doorClosed);
	doorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	doorFrame->SetupAttachment(RootComponent);
	doorFrame->SetRelativeLocation(doorClosed);

	doorOpenTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Timeline"));
	TimelineUpdate.BindUFunction(this, FName("UpdateDoorPosition"));
	TimelineFinished.BindUFunction(this, FName("OnTimelineFinished"));
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
	UpdateMouseoverText();
}

void ADoor::Interact()
{
	if (CanOpenDoor())
	{
		UGameplayStatics::PlaySoundAtLocation(this, DoorOpenSound, GetActorLocation());
		if (isOpen)
			CloseDoor();
		else
			OpenDoor();
	}
	else
	{
		UGameplayStatics::PlaySoundAtLocation(this, DoorLockedSound, GetActorLocation());
	}
}

void ADoor::UpdateMouseoverText()
{
	FString newMouseOverText;
	if (isLocked)
		newMouseOverText = "E To Interact, Locked";
	else
		newMouseOverText = "E To Interact, Unlocked";
	if (isAirtight)
		newMouseOverText += ", Sealed";
	else
		newMouseOverText += ", Unsealed";
	if (isBroken)
		newMouseOverText += ", Broken";

	mouseOverText = FText::AsCultureInvariant(newMouseOverText);
}

bool ADoor::CanOpenDoor()
{
	if (isLocked)
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Door Locked"));
		return false;
	}
	if (isBroken)
	{
		((ADerelictGameModeBase*)GetWorld()->GetAuthGameMode())->WriteToDisplay(FText::FromString("Door Broken"));
		return false;
	}
	return true;
}

void ADoor::UpdateDoorPosition(float value)
{
	doorMesh->SetRelativeLocation(FMath::Lerp(doorClosed, doorOpen, value));
}

void ADoor::OnTimelineFinished()
{
	isOpen = !isOpen;
}

void ADoor::Seal()
{
	isAirtight = true;
	for (int x = 0; x < 2; x++)
		linkedGasBPs[x]->UpdateGasStatus();
}

void ADoor::OpenDoor()
{
	if (DoorOpenCurve)
	{
		GLog->Log("TEST");
		doorOpenTimeline->AddInterpFloat(DoorOpenCurve, TimelineUpdate, FName("Alpha"));
		doorOpenTimeline->SetTimelineFinishedFunc(TimelineFinished);
		doorOpenTimeline->SetLooping(false);
		doorOpenTimeline->SetIgnoreTimeDilation(true);
		doorOpenTimeline->Play();
	}
}

void ADoor::CloseDoor()
{
	doorOpenTimeline->Reverse();
}