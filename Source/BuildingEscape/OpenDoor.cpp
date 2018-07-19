// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...	
}


// Called when the game starts
/************************************************************************************************/
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	//3.73 moved open door code out of here to its
	//..own function, and now will call elsewhere

	//3.74 Find the controller and then init the ActorThatOpens to the Pawn.
	UWorld* pWorld = GetWorld();
	APlayerController* pPlayerController = pWorld->GetFirstPlayerController();
	m_pActorThatOpens = pPlayerController->GetPawn();

	//3.76 Init ourselves
	m_pActor = GetOwner();

	return;
}

// Called every frame
/************************************************************************************************/
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//3.73 Poll trigger to see if pawn is overlapping
	if (m_pPressurePlate == nullptr)
		return;
	if (m_pActorThatOpens == nullptr)
		return;

	if (m_pPressurePlate->IsOverlappingActor(m_pActorThatOpens))
	{
		OpenTheDoor();
		//3.76
		m_LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	//3.76 check if time to close door
	float curTime = GetWorld()->GetTimeSeconds();
	if ((curTime - m_LastDoorOpenTime) > m_DoorCloseDelay)
		CloseTheDoor();

	return;
}

/************************************************************************************************/
void UOpenDoor::OpenTheDoor()
{
	//Lecture 3.73 : Moved this to its own funciton
	//Lecture 3.69
	//Get the door's rotation
	//AActor* pActor = GetOwner(); <--- made variabel in 3.76
	FRotator theRotation = FRotator(0.f, m_fOpenAngle, 0.f);

	m_pActor->SetActorRotation(theRotation);

	return;
}

/************************************************************************************************/
void UOpenDoor::CloseTheDoor(void)
{
	//Lecture 3.76
	//AActor* pActor = GetOwner(); <--- made variabel in 3.76
	m_pActor->SetActorRotation(FRotator(0, 0, 0));

	return;
}