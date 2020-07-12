// Copyright 2020 Darren Beukes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

// Forward declarations
class ATank; 

/**
 *
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
  GENERATED_BODY()
private:
  UPROPERTY(EditDefaultsOnly)
  float CrossHairXLocation = .5;

  UPROPERTY(EditDefaultsOnly)
  float CrossHairYLocation = .3333;

  UPROPERTY(EditDefaultsOnly)
  float LineTraceRange = 1000000.0; // unreal units in cm
public:
  ATank* GetControlledTank() const;

  virtual void BeginPlay() override;
  virtual void Tick(float DeltaSeconds) override;
  void AimTowardsCrossHair() const;
  bool GetSightRayHitLocation(FVector &OutHitLocation) const;
  bool GetLookVectorHitLocation(FVector &OutHitLocation,  FVector LookDirection) const;
};
