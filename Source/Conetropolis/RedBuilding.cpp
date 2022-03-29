// Fill out your copyright notice in the Description page of Project Settings.


#include "RedBuilding.h"

ARedBuilding::ARedBuilding()
{
	static FConstructorStatics ConstructorStatics;
	
	buildingQuantity=20;
	buildingName="Red";
	scoreAward = 10;
	Color=EColor::RED;
	ConeMesh->SetMaterial(0, ConstructorStatics.RedMaterial.Get());
}
