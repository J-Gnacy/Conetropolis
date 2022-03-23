// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BuildingButton.generated.h"

/**
 * 
 */
UCLASS()
class CONETROPOLIS_API UBuildingButton : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* BButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* BuildingName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* BuildingQuantity;
};
