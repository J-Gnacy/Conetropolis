// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ColoredObject.h"
#include "ConeBuilding.generated.h"

/**
 * 
 */
UCLASS()
class CONETROPOLIS_API AConeBuilding : public AColoredObject
{
	GENERATED_BODY()



public:
	AConeBuilding();

	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ConeMesh;
	
	UPROPERTY()
	int buildingQuantity;

	UPROPERTY()
	FString buildingName;

	UPROPERTY()
	int scoreAward;
	
};
