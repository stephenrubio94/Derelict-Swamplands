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
	if (CraftingWidget)
	{
		craftingWidget = CreateWidget<UUserWidget>(this, CraftingWidget);

		if (craftingWidget)
		{
			craftingWidget->AddToViewport();
			craftingWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void ADerelictPlayerControllerBase::ToggleCraftingMenu()
{
	if (craftingWidget->GetVisibility() == ESlateVisibility::Hidden)
	{
		craftingWidget->SetVisibility(ESlateVisibility::Visible);
		bShowMouseCursor = true;
		bEnableClickEvents = true;
		bEnableMouseOverEvents = true;
		IgnoreLookInput = true;
		SetInputMode(FInputModeGameAndUI());
	}
	else
	{
		craftingWidget->SetVisibility(ESlateVisibility::Hidden);
		bShowMouseCursor = false;
		bEnableClickEvents = false;
		bEnableMouseOverEvents = false;
		IgnoreLookInput = false;
		SetInputMode(FInputModeGameOnly());
	}
}