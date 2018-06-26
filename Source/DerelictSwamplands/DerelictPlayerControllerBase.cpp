#include "DerelictPlayerControllerBase.h"
#include "FPMainWidgetBase.h"
#include "Blueprint/UserWidget.h"

void ADerelictPlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	if (FPMainWidget)
	{
		mainWidget = CreateWidget<UUserWidget>(this, FPMainWidget);

		if (mainWidget)
			mainWidget->AddToViewport();
	}
}