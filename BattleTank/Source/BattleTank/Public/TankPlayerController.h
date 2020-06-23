// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "TankPlayerController.generated.h"

/**
 *
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
  GENERATED_BODY()
private:
  UPROPERTY(EditAnywhere)
  float CrossHairXLocation = .5;

  UPROPERTY(EditAnywhere)
  float CrossHairYLocation = .3333;

  UPROPERTY(EditAnywhere)
  float LineTraceRange = 1000000.0; // unreal units in cm
public:
  ATank* GetControlledTank() const;

  virtual void BeginPlay() override;
  virtual void Tick(float DeltaSeconds) override;
  void AimTowardsCrossHair() const;
  bool GetSightRayHitLocation(FVector &OutHitLocation) const;
  bool GetLookVectorHitLocation(FVector &OutHitLocation,  FVector LookDirection) const;
};
