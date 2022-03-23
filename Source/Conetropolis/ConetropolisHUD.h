// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Components/WidgetComponent.h"
#include "BuilderWidget.h"
#include "ConetropolisHUD.generated.h"

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

private:
	UPROPERTY()
	UBuilderWidget* BuilderWidget;
};
