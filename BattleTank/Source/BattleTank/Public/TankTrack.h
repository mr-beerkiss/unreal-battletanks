// Copyright 2020 Darren Beukes

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
  GENERATED_BODY()

public:
  /**
   * Set the tank throttle value
  */
  UFUNCTION(BlueprintCallable, Category=Controls)
  void SetThrottle(float Throttle);

};
