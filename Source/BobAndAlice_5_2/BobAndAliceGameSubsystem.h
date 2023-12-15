// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BobAndAliceGameSubsystem.generated.h"
#include "Subsystems/GameInstanceSubsystem.h"

UCLASS ()
class BOBANDALICE_5_2_API UBobAndAliceGameSubsystem
	: public UGameInstanceSubsystem
{
	GENERATED_BODY ()

public:
	virtual void Initialize (FSubsystemCollectionBase &Collection) override;

	virtual void Deinitialize () override;

	void StartCountDown (float duration);
	void UpdateCountDown (float deltaTime);
	float GetCountdownTime () const;

private:
	float CountdownTime;
};
