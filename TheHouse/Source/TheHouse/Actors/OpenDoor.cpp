// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"

static constexpr float s_OpenDoorTime = 1.618f * 2.0f;

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	m_State = NONE;
	m_DefaultAngle = 0.0f;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	m_DefaultAngle = GetOwner()->GetActorRotation().Yaw;
	SetState(DOOR_OPEN);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	switch (m_State)
	{
	case DOOR_OPEN: {
		FRotator currentRotator = GetOwner()->GetActorRotation();
		if (m_DefaultAngle - m_DoorRotatorAngle != currentRotator.Yaw) {
			currentRotator.Yaw -= m_DoorRotatorAngle * DeltaTime / s_OpenDoorTime;
			if (m_DefaultAngle - m_DoorRotatorAngle > currentRotator.Yaw) {
				currentRotator.Yaw = m_DefaultAngle - m_DoorRotatorAngle;
				SetState(DOOR_CLOSE);
			}
			GetOwner()->SetActorRotation(currentRotator);
		}
		}
		break;
	case DOOR_CLOSE:{
		FRotator currentRotator = GetOwner()->GetActorRotation();
		if (m_DefaultAngle != currentRotator.Yaw) {
			currentRotator.Yaw += m_DoorRotatorAngle * DeltaTime / s_OpenDoorTime;
			if (m_DefaultAngle < currentRotator.Yaw) {
				currentRotator.Yaw = m_DefaultAngle;
				SetState(DOOR_OPEN);
			}
			GetOwner()->SetActorRotation(currentRotator);
		}
		}
		break;
	case NONE:
	default:
		break;
	}

}

void UOpenDoor::SetState(int state) {
	switch (state)
	{
	case NONE:
	default:
		break;
	}
	m_State = state;
}
