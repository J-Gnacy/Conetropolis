// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ColoredObject.h"
#include "ConeBuilding.h"
#include "GameFramework/Actor.h"
#include "GridField.generated.h"

/** A block that can be clicked */
UCLASS(minimalapi)
class AGridField : public AColoredObject
{
	GENERATED_BODY()

	/** Dummy root component */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRoot;

	/** StaticMesh component for the clickable block */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* FieldMesh;

public:
	AGridField();

	/** Are we currently active? */
	bool bIsActive;

	/** Grid that owns us */
	UPROPERTY()
	class AGrid* OwningGrid;

	/** Handle the block being clicked */
	UFUNCTION()
	void BlockClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked);

	/** Handle the block being touched  */
	UFUNCTION()
	void OnFingerPressedBlock(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent);

	void HandleClicked();

	void Highlight(bool bOn);

	void BuildCone(AConeBuilding ConeToBuild);

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AConeBuilding> SpawnedCone;
	
	/** Returns DummyRoot subobject **/
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot; }
	/** Returns BlockMesh subobject **/
	FORCEINLINE class UStaticMeshComponent* GetBlockMesh() const { return FieldMesh; }
};



