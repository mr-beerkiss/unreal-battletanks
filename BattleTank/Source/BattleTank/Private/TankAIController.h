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

public:
  ATank* GetControlledTank() const;
  ATank* GetPlayerTank() const;
  virtual void BeginPlay() override;
  virtual void Tick(float DeltaSeconds) override;
	
};
