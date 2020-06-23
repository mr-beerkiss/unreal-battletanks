// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlledTank() const
{
  return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
  Super::BeginPlay();
  
  const auto ControlledTank = GetControlledTank();
 
  if (ControlledTank)
  {
    UE_LOG(LogTemp, Warning, TEXT("Controlled Tank = %s"), *ControlledTank->GetName());  
  }
  else
  {
    UE_LOG(LogTemp, Error, TEXT("Could not GET a controlled tank!"));
  }
  
  
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

  const bool bHitSomething = GetSightRayHitLocation(HitLocation);

  // UE_LOG(LogTemp, Warning, TEXT("Player viewpoint = %s"), *HitLocation.ToString());

  if (bHitSomething)
  {
    // Aim Barrel at Location of HitLocation
  }
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
  
  FVector PlayerViewPointLocation;
  FRotator PlayerViewPointRotation;
  this->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);
    
  // Find the location of the crosshair (it's in 2D space and in a Blueprint so that's weird)
  // Need to "de-project" the screen position of cross hair to world position
  int32 ViewportSizeX, ViewportSizeY;
  GetViewportSize(ViewportSizeX, ViewportSizeY);

  // messy implicit type coercion :yuck:
  const FVector2D ScreenLocation(CrossHairXLocation * ViewportSizeX, CrossHairYLocation * ViewportSizeY);

  FVector WorldLocation, WorldDirection;

  if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldDirection))
  {
    // Line Trace through the cross from the POV of the player controller. Might need to offset the POV
    // to from the edge of the barrel
    // Test the line trace to see if it hits any actors (does the landscape count as an actor)
    // Set a max range
   if (GetLookVectorHitLocation(OutHitLocation, WorldDirection))
   {
     UE_LOG(LogTemp, Warning, TEXT("Got a hit location %s"), *OutHitLocation.ToString());
     return true;
   }
  }
  
  return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector &OutHitLocation, FVector LookDirection) const
{
  // Get the Camera Location
  auto PlayerLocation = PlayerCameraManager->GetCameraLocation();
  FVector LineTraceEnd = PlayerLocation + LookDirection * LineTraceRange;
  FHitResult HitResult;

  // DrawDebugLine(GetWorld(), PlayerLocation, LineTraceEnd, FColor(0, 255, 0), false, 0.f, 0, 5);
  
  FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
  
  bool bHitSomething = GetWorld()->LineTraceSingleByChannel(
    HitResult,
    PlayerLocation,
    LineTraceEnd,
    ECC_Visibility,
    TraceParams);
  
  if (bHitSomething)
  {
    OutHitLocation = HitResult.Location;
  }
  
  return bHitSomething;
}