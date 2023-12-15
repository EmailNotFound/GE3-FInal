#include "BobAndAliceGameSubsystem.h"

void
UBobAndAliceGameSubsystem::Initialize (FSubsystemCollectionBase &Collection)
{
	Super::Initialize (Collection);
}

void
UBobAndAliceGameSubsystem::Deinitialize ()
{
	Super::Deinitialize ();
}

void
UBobAndAliceGameSubsystem::StartCountdown (float Duration)
{
	CountdownTime = Duration;
}

void
UBobAndAliceGameSubsystem::UpdateCountdown (float DeltaTime)
{
	if (CountdownTime > 0.0f)
		{
			CountdownTime -= DeltaTime;
		}
}

float
UBobAndAliceGameSubsystem::GetCountdownTime () const
{
	return CountdownTime;
}

void
AExampleActor::BeginPlay ()
{
	Super::BeginPlay ();

	UBobAndAliceGameSubsystem *MySubsystem
		= GetGameInstance ()->GetSubsystem<UBobAndAliceGameSubsystem> ();
	if (MySubsystem)
		{
			// Start the countdown with a 5-minute duration
			MySubsystem->StartCountdown (300.0f);
		}
}

void
AExampleActor::Tick (float DeltaTime)
{
	Super::Tick (DeltaTime);

	UBobAndAliceGameSubsystem *MySubsystem
		= GetGameInstance ()->GetSubsystem<UBobAndAliceGameSubsystem> ();
	if (MySubsystem)
		{
			// Update the countdown timer
			MySubsystem->UpdateCountdown (DeltaTime);

			// For example, print the remaining time to the output log
			UE_LOG (LogTemp, Log, TEXT ("Time remaining: %f"),
			        MySubsystem->GetCountdownTime ());
		}
}