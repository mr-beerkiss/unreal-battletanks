// Copyright 2020 Darren Beukes


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
  RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0);
  
  auto YawChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
  auto Yaw = RelativeRotation.Yaw + YawChange;
  
  SetRelativeRotation(FRotator(0, Yaw, 0));
}
