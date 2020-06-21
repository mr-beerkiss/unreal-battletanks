// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
  return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
  const auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
  if (!PlayerPawn) return nullptr;
  return Cast<ATank>(PlayerPawn);
}

void ATankAIController::BeginPlay()
{
  Super::BeginPlay();

  const auto ControlledTank = GetControlledTank();

  if (ControlledTank)
  {
    UE_LOG(LogTemp, Warning, TEXT("AI Controlled Tank = %s"),
           *ControlledTank->GetName());
  }
  else
  {
    UE_LOG(LogTemp, Error, TEXT("Could not get controlled tank"));
  }

  const auto PlayerTank = GetPlayerTank();

  if (PlayerTank)
  {
    const FString AIName = ControlledTank
                             ? ControlledTank->GetName()
                             : "No name";
    const FString PlayerTankName = PlayerTank->GetName();
    const FString PlayerTankPosition = PlayerTank
                                       ->GetActorLocation().ToString();
    UE_LOG(LogTemp, Warning, TEXT("%s found %s at %s"), *AIName,
           *PlayerTankName, *PlayerTankPosition);
  }
  else
  {
    UE_LOG(LogTemp, Error, TEXT("Unable to locate player tank"));
  }
}

void ATankAIController::Tick(float DeltaSeconds)
{
  Super::Tick(DeltaSeconds);
}
