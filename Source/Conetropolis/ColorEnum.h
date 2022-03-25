// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ColorEnum.generated.h"
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

struct FConstructorStatics
{
	ConstructorHelpers::FObjectFinderOptional<UStaticMesh> PlaneMesh;
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
		: PlaneMesh(TEXT("/Game/Meshes/PuzzleCube.PuzzleCube"))
		, BaseMaterial(TEXT("/Game/Materials/BaseMaterial.BaseMaterial"))
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

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CONETROPOLIS_API UColorEnum : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UColorEnum();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
