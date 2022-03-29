// Fill out your copyright notice in the Description page of Project Settings.


#include "YellowBuilding.h"

AYellowBuilding::AYellowBuilding()
{
	static FConstructorStatics ConstructorStatics;
	
	buildingQuantity=25;
	buildingName="Yellow";
	scoreAward = 8;
	Color=EColor::YELLOW;
	ConeMesh->SetMaterial(0, ConstructorStatics.YellowMaterial.Get());
}
