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
	InitializeWidgets();
	
}

void AConetropolisHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AConetropolisHUD::SetScore(int score)
{
	if(ScoreWidget)
	{
		ScoreWidget->SetScore(score);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("There is no ScoreWidget in HUD"));
	}
	
}

void AConetropolisHUD::InitializeScoreWidget()
{
	if(ScoreWidgetClass)
	{
		ScoreWidget = CreateWidget<UScoreWidget>(GetWorld(), ScoreWidgetClass);
		{
			if(ScoreWidget)
			{
				ScoreWidget->AddToViewport();
			}
		}
	}
}

void AConetropolisHUD::InitializeBuilderWidget()
{
	if(BuilderWidgetClass)
	{
		BuilderWidget = CreateWidget<UBuilderWidget>(GetWorld(), BuilderWidgetClass);
		{
			if(BuilderWidget)
			{
				BuilderWidget->AddToViewport();
				BuilderWidget->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}
}


void AConetropolisHUD::InitializeWidgets()
{
	InitializeBuilderWidget();
	InitializeScoreWidget();
	SetScore(0);
	UE_LOG(LogTemp, Warning, TEXT("Widgets initialized"));
}

void AConetropolisHUD::ShowBuilderWidget()
{
	BuilderWidget->SetVisibility(ESlateVisibility::Visible);
}

void AConetropolisHUD::HideBuilderWidget()
{
	BuilderWidget->SetVisibility(ESlateVisibility::Hidden);
}

