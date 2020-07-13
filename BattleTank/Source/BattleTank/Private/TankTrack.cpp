// Copyright 2020 Darren Beukes


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
  UE_LOG(LogTemp, Warning, TEXT("Move track for %s with acceleration %.4f"), *GetName(), Throttle);
}
