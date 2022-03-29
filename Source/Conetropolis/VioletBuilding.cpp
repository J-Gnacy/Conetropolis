// Fill out your copyright notice in the Description page of Project Settings.


#include "VioletBuilding.h"

AVioletBuilding::AVioletBuilding()
{
	static FConstructorStatics ConstructorStatics;
	
	buildingQuantity=40;
	buildingName="Violet";
	scoreAward = 5;
	Color=EColor::VIOLET;
	ConeMesh->SetMaterial(0, ConstructorStatics.VioletMaterial.Get());
}
