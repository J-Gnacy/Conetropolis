// Fill out your copyright notice in the Description page of Project Settings.


#include "WhiteBuilding.h"

AWhiteBuilding::AWhiteBuilding()
{
	static FConstructorStatics ConstructorStatics;
	
	buildingQuantity=35;
	buildingName="White";
	scoreAward = 6;
	Color=EColor::WHITE;
	ConeMesh->SetMaterial(0, ConstructorStatics.WhiteMaterial.Get());
}
