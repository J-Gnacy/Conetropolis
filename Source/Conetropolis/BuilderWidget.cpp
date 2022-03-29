// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderWidget.h"

#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"

UBuilderWidget::UBuilderWidget(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
}

void UBuilderWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UBuilderWidget::AddChildToScrollbox(AConeBuilding* Building)
{
	if(BuildingButtonClass)
	{
		BButton = CreateWidget<UBuildingButton>(GetWorld(),BuildingButtonClass);
		UE_LOG(LogTemp, Warning, TEXT("BuildingButtonClass"))

		if(BButton)
		{
			BuilderScrollbox->AddChild(BButton);
			BButton->SetVisibility(ESlateVisibility::Visible);
			BButton->SetName(Building->buildingName);
	        BButton->BuildingQuantityText->SetText(FText::FromString(FString::FromInt(Building->buildingQuantity)));
		} 
		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NoBuildingButtonClass"))
	}
}
