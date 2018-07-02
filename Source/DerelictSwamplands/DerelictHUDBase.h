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
#include "CraftingWidgetBase.h"
#include "DerelictHUDBase.generated.h"

UCLASS()
class ADerelictHUDBase : public AHUD
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
		UFPMainWidgetBase* mainWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
		UCraftingWidgetBase* craftingWidget;
};

