#include "Door.h"
#include "GasBase.h"

ADoor::ADoor()
{
	isLocked = false;
	isAirtight = true;
	isBroken = false;
	isOpen = false;
	linkedGasBPs.Init(nullptr, 2);

	//Sets up door mesh
	doorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	doorMesh->SetupAttachment(RootComponent);
	doorMesh->SetRelativeLocation(doorClosed);
	doorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	doorFrame->SetupAttachment(RootComponent);
	doorFrame->SetRelativeLocation(doorClosed);

	doorOpenTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Timeline"));
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
	UpdateMouseoverText();

	//Sets up door open timeline components
	FOnTimelineFloat onTimelineCallback;
	FOnTimelineEventStatic onTimelineFinishedCallback;
	doorOpenTimeline = NewObject<UTimelineComponent>(this, FName("TimelineAnimation"));
	this->BlueprintCreatedComponents.Add(doorOpenTimeline);
	doorOpenTimeline->SetDirectionPropertyName(FName("TimelineDirection"));
	doorOpenTimeline->SetTimelineLength(3.0f);
	onTimelineCallback.BindUFunction(this, FName{ TEXT("TimelineUpdate") });
	onTimelineFinishedCallback.BindUFunction(this, FName{ TEXT("TimelineFinished") });
	doorOpenTimeline->AddInterpFloat(DoorOpenCurve, onTimelineCallback);
	doorOpenTimeline->SetTimelineFinishedFunc(onTimelineFinishedCallback);
	doorOpenTimeline->RegisterComponent();

	doorClosed = doorMesh->GetRelativeTransform().GetLocation();
	doorOpen = FVector(doorClosed.X + 110, doorClosed.Y, doorClosed.Z);
}

void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (doorOpenTimeline != NULL)
		doorOpenTimeline->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, NULL);
}


void ADoor::Interact()
{
	//If door is closed, open it.  If door is open, close it.
	if (CanOpenDoor())
	{
		UGameplayStatics::PlaySoundAtLocation(this, DoorOpenSound, GetActorLocation());
		if (isOpen)
			doorOpenTimeline->Reverse();
		else
			doorOpenTimeline->PlayFromStart();
		isOpen = !isOpen;
	}
	else
		UGameplayStatics::PlaySoundAtLocation(this, DoorLockedSound, GetActorLocation());
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
	if (isLocked || isBroken)
		return false;
	else
		return true;
}

void ADoor::TimelineUpdate(float value)
{
	doorMesh->SetRelativeLocation(FMath::Lerp(doorClosed, doorOpen, value));
}

void ADoor::TimelineFinished() {}

void ADoor::Seal()
{
	isAirtight = true;
	for (int x = 0; x < 2; x++)
		linkedGasBPs[x]->UpdateGasStatus();
}