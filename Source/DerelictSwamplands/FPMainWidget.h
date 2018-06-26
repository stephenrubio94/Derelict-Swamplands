

#pragma once

#include "CoreMinimal.h"
#include "WidgetBlueprint.h"
#include "FPMainWidget.generated.h"

/**
 * 
 */
UCLASS()
class DERELICTSWAMPLANDS_API UFPMainWidget : public UWidgetBlueprint
{
	GENERATED_BODY()
public:
	void WriteToHUD(FText textToWrite);
	void SetMouseOverText(FText mouseOverText);
};
