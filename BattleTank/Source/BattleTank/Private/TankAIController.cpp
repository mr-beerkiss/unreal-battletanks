// Copyright 2020 Darren Beukes

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

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
}

void ATankAIController::Tick(float DeltaSeconds)
{
  Super::Tick(DeltaSeconds);

  const auto AITank = GetControlledTank();
  
  if (AITank)
  {
    const auto PlayerTank = GetPlayerTank();

    if (PlayerTank)
    {
      AITank->AimAt(PlayerTank->GetActorLocation());
    }
  }
  
}
