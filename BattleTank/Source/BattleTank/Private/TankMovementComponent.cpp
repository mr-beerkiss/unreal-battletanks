// Copyright 2020 Darren Beukes


#include "TankMovementComponent.h"

#include "GenericApplicationMessageHandler.h"
#include "TankTrack.h"

void UTankMovementComponent::IntendMoveForward(float Throw)
{
  if (!LeftTrack || !RightTrack)
  {
    UE_LOG(LogTemp, Error, TEXT("Both Left and Right Tank Tracks must be set!"));
    return;
  }

  // UE_LOG(LogTemp, Warning, TEXT("Apply throw force of %.4f"), Throw);
  
  LeftTrack->SetThrottle(Throw);
  RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
  if (!LeftTrack || !RightTrack)
  {
    UE_LOG(LogTemp, Error, TEXT("Both Left and Right Tank Tracks must be set!"));
    return;
  }

  UE_LOG(LogTemp, Warning, TEXT("Apply turning force of %.4f"), Throw);

  LeftTrack->SetThrottle(Throw);
  RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet,
                                        UTankTrack* RightTrackToSet)
{
  if (!LeftTrackToSet || !RightTrackToSet)
  {
    UE_LOG(LogTemp, Error, TEXT("Both Left and Right Tank Tracks must be set!"));
    return;
  }
  
  LeftTrack = LeftTrackToSet;
  RightTrack = RightTrackToSet;
}
