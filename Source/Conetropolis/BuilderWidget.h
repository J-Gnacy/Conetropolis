// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BuildingButton.h"
#include "ConeBuilding.h"
#include "BuilderWidget.generated.h"

/**
 * 
 */
UCLASS()
class CONETROPOLIS_API UBuilderWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UBuilderWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UBorder* BuilderBorder;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UScrollBox* BuilderScrollbox;

	void AddChildToScrollbox(AConeBuilding* Building);

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> BuildingButtonClass;

	UPROPERTY()
	UBuildingButton* BButton;

	
	
	
};
