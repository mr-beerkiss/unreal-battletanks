// Copyright 2020 Darren Beukes

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UTankTurret : public UStaticMeshComponent
{
  GENERATED_BODY()
public:
  void Rotate(float RelativeSpeed);
private:
  UPROPERTY(EditAnywhere, Category=Setup)
  float MaxDegreesPerSecond = 25.0f;
};
