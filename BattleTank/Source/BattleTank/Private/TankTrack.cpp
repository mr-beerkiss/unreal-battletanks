// Copyright 2020 Darren Beukes


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
  UE_LOG(LogTemp, Warning, TEXT("Move track for %s with acceleration %.4f"), *GetName(), Throttle);

  auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
  auto ForcedLocation = GetComponentLocation();

  auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

  TankRoot->AddForceAtLocation(ForceApplied, ForcedLocation);
}
