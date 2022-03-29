// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ColoredObject.generated.h"

struct FConstructorStatics
{
	ConstructorHelpers::FObjectFinderOptional<UMaterial> BaseMaterial;
	ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> BlueMaterial;
	ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> OrangeMaterial;
	ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> GreenMaterial;
	ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> GreyMaterial;
	ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> RedMaterial;
	ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> YellowMaterial;
	ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> WhiteMaterial;
	ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> VioletMaterial;
		
	FConstructorStatics()
		: BaseMaterial(TEXT("/Game/Materials/BaseMaterial.BaseMaterial"))
		, BlueMaterial(TEXT("/Game/Materials/BlueMaterial.BlueMaterial"))
		, OrangeMaterial(TEXT("/Game/Materials/OrangeMaterial.OrangeMaterial"))
		, GreenMaterial(TEXT("/Game/Materials/GreenMaterial.GreenMaterial"))
		, GreyMaterial(TEXT("/Game/Materials/GreyMaterial.GreyMaterial"))
		, RedMaterial(TEXT("/Game/Materials/RedMaterial.RedMaterial"))
		, YellowMaterial(TEXT("/Game/Materials/YellowMaterial.YellowMaterial"))
		, WhiteMaterial(TEXT("/Game/Materials/WhiteMaterial.WhiteMaterial"))
		, VioletMaterial(TEXT("/Game/Materials/VioletMaterial.VioletMaterial"))
	{
	}
};

UENUM()
enum class EColor : uint8 {
	BLUE			UMETA(DisplayName = "Blue"),
	GREEN			UMETA(DisplayName = "Green"),
	GREY			UMETA(DisplayName = "Grey"),
	RED				UMETA(DisplayName = "Red"),
	VIOLET			UMETA(DisplayName = "Violet"),
	WHITE			UMETA(DisplayName = "White"),
	YELLOW			UMETA(DisplayName = "Yellow"),

};

UCLASS()
class CONETROPOLIS_API AColoredObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AColoredObject();

	UPROPERTY()
	class UMaterial* BaseMaterial;

	UPROPERTY()
	class UMaterialInstance* BlueMaterial;

	UPROPERTY()
	class UMaterialInstance* OrangeMaterial;

	UPROPERTY()
	class UMaterialInstance* GreenMaterial;

	UPROPERTY()
	class UMaterialInstance* GreyMaterial;

	UPROPERTY()
	class UMaterialInstance* RedMaterial;

	UPROPERTY()
	class UMaterialInstance* VioletMaterial;

	UPROPERTY()
	class UMaterialInstance* WhiteMaterial;

	UPROPERTY()
	class UMaterialInstance* YellowMaterial;

	UPROPERTY()
	EColor Color;

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

};
