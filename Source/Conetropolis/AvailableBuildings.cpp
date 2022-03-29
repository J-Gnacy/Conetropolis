// Fill out your copyright notice in the Description page of Project Settings.


#include "AvailableBuildings.h"

// Sets default values for this component's properties
UAvailableBuildings::UAvailableBuildings()
{
	ConeBuildingClass=AConeBuilding::StaticClass();
	RedBuilding=CreateDefaultSubobject<ARedBuilding>(TEXT("RedBuilding"));
	YellowBuilding=CreateDefaultSubobject<AYellowBuilding>(TEXT("YellowBuilding"));
	WhiteBuilding=CreateDefaultSubobject<AWhiteBuilding>(TEXT("WhiteBuilding"));
	VioletBuilding=CreateDefaultSubobject<AVioletBuilding>(TEXT("VioletBuilding"));
}


// Called when the game starts
void UAvailableBuildings::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAvailableBuildings::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAvailableBuildings::ShowAvailableBuildings()
{
/*	UWorld* GameWorld = GetWorld();
	AConetropolisHUD* HUD = Cast<AConetropolisHUD>(GameWorld->GetFirstPlayerController()->GetHUD());
	if(HUD)
	{
		HUD->ShowBuilderWidget();
		RedBuilding=NewObject<AConeBuilding>(ConeBuildingClass);
		if(RedBuilding)
		{
			HUD->BuilderWidget->AddChildToScrollbox(RedBuilding);
			int quantity = RedBuilding->buildingQuantity;
			UE_LOG(LogTemp, Warning, TEXT("Testing quantity %d"), quantity);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("There is no Building"));
		}
	} */
}

