// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Components/WidgetComponent.h"
#include "BuilderWidget.h"
#include "ScoreWidget.h"
#include "ConetropolisHUD.generated.h"

class UClassTemplate;
/**
 * 
 */
UCLASS()
class CONETROPOLIS_API AConetropolisHUD : public AHUD
{
	GENERATED_BODY()

public:
	AConetropolisHUD();
	virtual void DrawHUD() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> BuilderWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> ScoreWidgetClass;

	void SetScore(int score);
	
	UPROPERTY()
	UBuilderWidget* BuilderWidget;
	UPROPERTY()
	UScoreWidget* ScoreWidget;
	
	
    void InitializeScoreWidget();
    void InitializeBuilderWidget();
	void InitializeWidgets();
	void ShowBuilderWidget();
	void HideBuilderWidget();

};



