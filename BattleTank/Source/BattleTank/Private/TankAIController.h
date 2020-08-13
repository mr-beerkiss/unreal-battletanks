// Copyright 2020 Darren Beukes

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

// Forward declarations
class ATank;

/**
 * 
 */
UCLASS()
class ATankAIController : public AAIController
{
  GENERATED_BODY()
private:
  // How can close should AI try get to the player
  UPROPERTY(EditDefaultsOnly) 
  float AcceptanceRadius = 3000;
public:
  virtual void BeginPlay() override;
  virtual void Tick(float DeltaSeconds) override;
};
