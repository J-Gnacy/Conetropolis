// Copyright Epic Games, Inc. All Rights Reserved.

#include "GridField.h"

#include "Grid.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstance.h"

AGridField::AGridField()
{
	static FConstructorStatics ConstructorStatics;

	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;
	
	FieldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh0"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Game/Meshes/PuzzleCube.PuzzleCube"));
	FieldMesh->SetStaticMesh(MeshAsset.Object);
	FieldMesh->SetRelativeScale3D(FVector(1.f,1.f,0.25f));
	FieldMesh->SetRelativeLocation(FVector(0.f,0.f,25.f));
	FieldMesh->SetMaterial(0, ConstructorStatics.BlueMaterial.Get());
	FieldMesh->SetupAttachment(DummyRoot);
	FieldMesh->OnClicked.AddDynamic(this, &AGridField::BlockClicked);
	FieldMesh->OnInputTouchBegin.AddDynamic(this, &AGridField::OnFingerPressedBlock);

	SpawnedCone = AConeBuilding::StaticClass();
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
	if (!bIsActive)
	{
		bIsActive = true;

		FieldMesh->SetMaterial(0, OrangeMaterial);
		if(OwningGrid)
			OwningGrid->AddScore();
		else
			UE_LOG(LogTemp, Warning, TEXT("No OwningGrid in GridField"));
		
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
		FieldMesh->SetMaterial(0, BaseMaterial);
	}
	else
	{
		FieldMesh->SetMaterial(0, BlueMaterial);
	}
}

void AGridField::BuildCone(AConeBuilding ConeToBuild)
{
	UWorld* GameWorld=GetWorld();
	if(GameWorld)
	{
		SpawnedCone=ConeToBuild.GetClass();
		const FRotator rotation;
		const FVector spawnLocation = this->GetActorLocation();
		const FActorSpawnParameters spawnParameters;
		GameWorld->SpawnActor<AConeBuilding>(SpawnedCone, spawnLocation, rotation, spawnParameters);
	}
	
	
}
