// Copyright 2020 Darren Beukes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsible for driving the tank tracks
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UTankMovementComponent : public UNavMovementComponent
{
  GENERATED_BODY()
public:
  UFUNCTION(BlueprintCallable, Category=Movement)
  void IntendMoveForward(float Throw);

  UFUNCTION(BlueprintCallable, Category=Movement)
  void IntendTurnRight(float Throw);

  UFUNCTION(BlueprintCallable, Category=Movement)
  void Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

  virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
private:
  UPROPERTY(EditDefaultsOnly, Category=Movement)
  UTankTrack* LeftTrack = nullptr;
  
  UPROPERTY(EditDefaultsOnly, Category=Movement)
  UTankTrack* RightTrack = nullptr;
};
