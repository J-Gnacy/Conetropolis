// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BuildingButton.h"
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

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UBorder* BuilderBorder;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UScrollBox* BuilderScrollbox;

	void AddChildToScrollbox();

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> BuilderWidgetClass;
	UBuildingButton* BuildingButton;

	
	
	
};
