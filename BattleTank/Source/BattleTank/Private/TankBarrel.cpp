// Copyright 2020 Darren Beukes


#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
  RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0);
  
  auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
  auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

  auto Elevation = FMath::Clamp<float>(RawNewElevation, MinimumElevationDegrees, MaximumElevationDegrees);

  SetRelativeRotation(FRotator(Elevation, 0, 0));
}
