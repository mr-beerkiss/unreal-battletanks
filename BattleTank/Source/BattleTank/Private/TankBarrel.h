// Copyright 2020 Darren Beukes

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 *  Holds barrel values and elevate method
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UTankBarrel : public UStaticMeshComponent
{
  GENERATED_BODY()
public:
  void Elevate(float RelativeSpeed);
private:
  UPROPERTY(EditDefaultsOnly, Category=Setup)
  float MaxDegreesPerSecond = 10.0f;

  UPROPERTY(EditDefaultsOnly, Category=Setup)
  float MinimumElevationDegrees = 0.0f;

  UPROPERTY(EditDefaultsOnly, Category=Setup)
  float MaximumElevationDegrees = 50.0f;
};
