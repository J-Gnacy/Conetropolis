// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"



UScoreWidget::UScoreWidget(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
}

void UScoreWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UScoreWidget::SetScore(int32 score)
{
	if(ScoreText)
	{
		ScoreText->SetText(FText::FromString(FString::FromInt(score)));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("There is no ScoreText in ScoreWidget"));
	}
	
}
