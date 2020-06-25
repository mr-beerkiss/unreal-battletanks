// Copyright 2020 Darren Beukes

#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
  return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
  Super::BeginPlay();
  // TODO: Why doesn't this work?
  SetName(TEXT("Player Tank"));
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
  Super::Tick(DeltaSeconds);
  AimTowardsCrossHair();
}

void ATankPlayerController::AimTowardsCrossHair() const
{
  if (!GetControlledTank())
    return;

  FVector HitLocation;

  if (GetSightRayHitLocation(HitLocation))
  {
    // Aim Barrel at Location of HitLocation
    GetControlledTank()->AimAt(HitLocation);
  }
}

bool ATankPlayerController::GetSightRayHitLocation(
    FVector& OutHitLocation) const
{
  // Find the location of the crosshair (it's in 2D space and in a Blueprint so that's weird)
  // Need to "de-project" the screen position of cross hair to world position
  int32 ViewportSizeX, ViewportSizeY;
  GetViewportSize(ViewportSizeX, ViewportSizeY);

  // messy implicit type coercion :yuck:
  const FVector2D ScreenLocation(CrossHairXLocation * ViewportSizeX,
                                 CrossHairYLocation * ViewportSizeY);

  FVector WorldLocation, WorldDirection;

  if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y,
                                     WorldLocation, WorldDirection))
  {
    // Line Trace through the cross from the POV of the player controller. Might need to offset the POV
    // to from the edge of the barrel
    // Test the line trace to see if it hits any actors (does the landscape count as an actor)
    // Set a max range
    return GetLookVectorHitLocation(OutHitLocation, WorldDirection);
  }

  return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(
    FVector& OutHitLocation, FVector LookDirection) const
{
  // Get the Camera Location
  const auto PlayerLocation = PlayerCameraManager->GetCameraLocation();
  const FVector LineTraceEnd = PlayerLocation + LookDirection * LineTraceRange;
  FHitResult HitResult;

  // DrawDebugLine(GetWorld(), PlayerLocation, LineTraceEnd, FColor(0, 255, 0), false, 0.f, 0, 5);

  // This is from teh Escape game. It can be sent as the 5th arg to LineTraceSingleByChannel,
  // however it doesn't seem to do anything...
  // FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

  if (GetWorld()->LineTraceSingleByChannel(
      HitResult,
      PlayerLocation,
      LineTraceEnd,
      ECC_Visibility))
  {
    OutHitLocation = HitResult.Location;
    return true;
  }
  OutHitLocation = FVector(0);
  return false;
}
