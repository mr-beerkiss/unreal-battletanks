// Copyright 2020 Darren Beukes


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
  RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0);
  
  auto YawChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
  auto RawYaw = RelativeRotation.Yaw + YawChange;

  auto Yaw = FMath::Clamp<float>(RawYaw, -180, 180);

  
  
  SetRelativeRotation(FRotator(0, Yaw, 0));
}
