// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingButton.h"

#include "Components/TextBlock.h"

void UBuildingButton::SetName(FString name)
{
	BuildingNameText->SetText(FText::FromString(name));
}
