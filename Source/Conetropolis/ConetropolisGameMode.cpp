// Copyright Epic Games, Inc. All Rights Reserved.

#include "ConetropolisGameMode.h"
#include "ConetropolisPawn.h"

AConetropolisGameMode::AConetropolisGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AConetropolisPawn::StaticClass();
}

