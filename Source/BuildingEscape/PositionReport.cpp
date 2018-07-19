// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReport.h"
//Now needed 3.63
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

	//Lecture 3.65 hard coded	
	//UE_LOG(LogTemp, Warning, TEXT("Position Report Reporting for Duty on Chair!"));
	//Lecture 3.66 : Use GetOwner()	
	FString ObjectName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("Position Report Reporting for Duty on %s!"), *ObjectName);
	
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

