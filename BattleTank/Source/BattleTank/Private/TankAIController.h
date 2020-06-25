// Copyright 2020 Darren Beukes

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankAIController.generated.h"

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
