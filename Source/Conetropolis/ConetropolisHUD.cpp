// Fill out your copyright notice in the Description page of Project Settings.


#include "ConetropolisHUD.h"

AConetropolisHUD::AConetropolisHUD()
{
	
}

void AConetropolisHUD::DrawHUD()
{
	Super::DrawHUD();
}

void AConetropolisHUD::BeginPlay()
{
	Super::BeginPlay();

	if(BuilderWidgetClass)
	{
		BuilderWidget = CreateWidget<UBuilderWidget>(GetWorld(), BuilderWidgetClass);
		{
			if(BuilderWidget)
			{
				BuilderWidget->AddToViewport();
			}
		}
	}
}

void AConetropolisHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

