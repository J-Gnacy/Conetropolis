// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "ScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class CONETROPOLIS_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UScoreWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* ScoreText;

	void SetScore(int32 score);
	

};
