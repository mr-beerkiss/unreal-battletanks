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
  // FString name = GetPawn()->GetName();
  //
  // UE_LOG(LogTemp, Warning, TEXT("Tick Pawn = %s"), *name);
}
