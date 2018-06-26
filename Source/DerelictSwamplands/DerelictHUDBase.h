// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"
#include "FPMainWidgetBase.h"
#include "DerelictHUDBase.generated.h"

UCLASS()
class ADerelictHUDBase : public AHUD
{
	GENERATED_BODY()

public:
	ADerelictHUDBase();
	virtual void BeginPlay() override;

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;
	void WriteToHUD(FText textToWrite);
	void SetMouseOverText(FText mouseOverText);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
		UFPMainWidgetBase* mainWidget;
};

