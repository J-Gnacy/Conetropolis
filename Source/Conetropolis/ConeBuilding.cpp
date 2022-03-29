// Fill out your copyright notice in the Description page of Project Settings.


#include "ConeBuilding.h"

AConeBuilding::AConeBuilding()
{
	static FConstructorStatics ConstructorStatics;

	ConeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh0"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Game/Meshes/Cone.Cone"));
	ConeMesh->SetStaticMesh(MeshAsset.Object);

	buildingQuantity = 999;
	buildingName="Default";
	scoreAward=999;
	Color=EColor::GREY;
}
