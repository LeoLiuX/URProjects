// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THEHOUSE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void	BeginPlay() override;
	virtual void	SetState(int state);
	enum eDoorState
	{
		NONE,
		DOOR_OPEN,
		DOOR_CLOSE,
		NUM_DOOR_STATE,
	};

private:
	float			m_DefaultAngle;
	int				m_State;

	UPROPERTY(EditAnywhere)
	float			m_DoorRotatorAngle = 60.0f;

	//UPROPERTY(EditAnywhere)
	ATriggerVolume* m_PressurePlate;

	UPROPERTY(EditAnywhere)
	AActor*			m_UserPawn;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	bool		 SetOpenDoor(bool bShouldOpen);
};
