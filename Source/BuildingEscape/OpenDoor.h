// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//3.72 for trigger volume
#include "Classes/Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenTheDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	//Next 2 : 3.72 adding UPROPERTY variables
	UPROPERTY(VisibleAnywhere)
	float m_fOpenAngle = 65.f;
	
	UPROPERTY(EditAnywhere)
	ATriggerVolume* m_pPressurePlate = NULL;

	//3.73 Add a pointer to the actor that opens the door
	UPROPERTY(EditAnywhere)
	AActor* m_pActorThatOpens;
};
