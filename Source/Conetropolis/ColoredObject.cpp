// Fill out your copyright notice in the Description page of Project Settings.


#include "ColoredObject.h"

AColoredObject::AColoredObject()
{
	static FConstructorStatics ConstructorStatics;
	BaseMaterial = ConstructorStatics.BaseMaterial.Get();
	BlueMaterial = ConstructorStatics.BlueMaterial.Get();
	OrangeMaterial = ConstructorStatics.OrangeMaterial.Get();
	GreenMaterial = ConstructorStatics.GreenMaterial.Get();
	GreyMaterial = ConstructorStatics.GreyMaterial.Get();
	RedMaterial = ConstructorStatics.RedMaterial.Get();
	VioletMaterial = ConstructorStatics.VioletMaterial.Get();
	WhiteMaterial = ConstructorStatics.WhiteMaterial.Get();
	YellowMaterial = ConstructorStatics.YellowMaterial.Get();
}

void AColoredObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColoredObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

