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

private:
  // Max Force per track in newtons  
  UPROPERTY(EditDefaultsOnly, Category=Setup)
  float TrackMaxDrivingForce = 400000.0f;
  // f = m x a;
  // a = 2.682m/s^2 (0-60mph in 10s);
  // a = 10ms/2 (1g) - Too fast for a real tank but probably ok for a game
  // m = 40,000kg
  // NOTE: Physics are impacted by unreal's internal measurement system in cm
  
  
public:
  /**
   * Set the tank throttle value
  */
  UFUNCTION(BlueprintCallable, Category=Controls)
  void SetThrottle(float Throttle);

};
