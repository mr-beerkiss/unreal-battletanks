// Copyright 2020 Darren Beukes

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
  Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)
{
  Super::Tick(DeltaSeconds);

  const auto AITank = Cast<ATank>(GetPawn());
  const auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
  
  if (!AITank || !PlayerTank)
    return;

  AITank->AimAt(PlayerTank->GetActorLocation());
  AITank->Fire();
}
