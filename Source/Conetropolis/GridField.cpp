// Copyright Epic Games, Inc. All Rights Reserved.

#include "GridField.h"
#include "Grid.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstance.h"

AGridField::AGridField()
{
	// Structure to hold one-time initialization
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
	static FConstructorStatics ConstructorStatics;

	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh0"));
	BlockMesh->SetStaticMesh(ConstructorStatics.PlaneMesh.Get());
	BlockMesh->SetRelativeScale3D(FVector(1.f,1.f,0.25f));
	BlockMesh->SetRelativeLocation(FVector(0.f,0.f,25.f));
	BlockMesh->SetMaterial(0, ConstructorStatics.BlueMaterial.Get());
	BlockMesh->SetupAttachment(DummyRoot);
	BlockMesh->OnClicked.AddDynamic(this, &AGridField::BlockClicked);
	BlockMesh->OnInputTouchBegin.AddDynamic(this, &AGridField::OnFingerPressedBlock);

	// Save a pointer to the orange material
	BaseMaterial = ConstructorStatics.BaseMaterial.Get();
	BlueMaterial = ConstructorStatics.BlueMaterial.Get();
	OrangeMaterial = ConstructorStatics.OrangeMaterial.Get();
}

void AGridField::BlockClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked)
{
	HandleClicked();
}


void AGridField::OnFingerPressedBlock(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent)
{
	HandleClicked();
}

void AGridField::HandleClicked()
{
	// Check we are not already active
	if (!bIsActive)
	{
		bIsActive = true;

		// Change material
		BlockMesh->SetMaterial(0, OrangeMaterial);
		
	}
}

void AGridField::Highlight(bool bOn)
{
	// Do not highlight if the block has already been activated.
	if (bIsActive)
	{
		return;
	}

	if (bOn)
	{
		BlockMesh->SetMaterial(0, BaseMaterial);
	}
	else
	{
		BlockMesh->SetMaterial(0, BlueMaterial);
	}
}
