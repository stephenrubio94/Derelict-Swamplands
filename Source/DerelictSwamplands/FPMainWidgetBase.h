#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FPMainWidgetBase.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API UFPMainWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Write Text To HUD"))
		void WriteToHUD(const FText & textToWrite);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Set Mouse Over Text"))
		void SetMouseOverText(const FText & testToWrite);
};
