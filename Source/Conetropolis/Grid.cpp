// Copyright Epic Games, Inc. All Rights Reserved.

#include "Grid.h"
#include "GridField.h"
#include "Components/TextRenderComponent.h"
#include "Engine/World.h"


AGrid::AGrid()
{
	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;
	

	// Set defaults
	Size = 3;
	BlockSpacing = 300.f;
	Score=0;
}


void AGrid::BeginPlay()
{
	Super::BeginPlay();
	HUD=Cast<AConetropolisHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if(HUD)
	{
		HUD->SetScore(Score);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("There is no HUD"));
	}
	
}


void AGrid::AddScore()
{
	// Increment score
	Score++;
	HUD->SetScore(Score);
	
}

void AGrid::BuildGrid(int desiredSize)
{
	if(desiredSize>1)
		Size=desiredSize;
	
	// Number of blocks
	const int32 NumBlocks = Size * Size;

	// Loop to spawn each block
	for(int32 BlockIndex=0; BlockIndex<NumBlocks; BlockIndex++)
	{
		const float XOffset = (BlockIndex/Size) * BlockSpacing; // Divide by dimension
		const float YOffset = (BlockIndex%Size) * BlockSpacing; // Modulo gives remainder

		// Make position vector, offset from Grid location
		const FVector BlockLocation = FVector(XOffset, YOffset, 0.f) + GetActorLocation();

		// Spawn a block
		AGridField* NewBlock = GetWorld()->SpawnActor<AGridField>(BlockLocation, FRotator(0,0,0));

		// Tell the block about its owner
		if (NewBlock != nullptr)
		{
			NewBlock->OwningGrid = this;
		} 
	} 
}