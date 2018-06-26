// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "DerelictHUDBase.h"


ADerelictHUDBase::ADerelictHUDBase()
{
}

void ADerelictHUDBase::BeginPlay()
{
}

void ADerelictHUDBase::DrawHUD()
{
	Super::DrawHUD();
}

void ADerelictHUDBase::WriteToHUD(FText textToWrite)
{
	mainWidget->WriteToHUD(textToWrite);
}

void ADerelictHUDBase::SetMouseOverText(FText mouseOverText)
{
	mainWidget->SetMouseOverText(mouseOverText);
}
