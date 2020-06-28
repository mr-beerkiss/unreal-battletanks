// Copyright 2020 Darren Beukes


#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
  // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
  // off to improve performance if you don't need them.
  PrimaryComponentTick.bCanEverTick = true;

  // ...
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) const
{
  if (Barrel)
  {
    // This could work but then you would need to offset
    // const FVector StartLocation = Barrel->GetComponentLocation();
    // An interesting method to get a more precise firing location is to create
    // a socket on the mesh and refer to it by name.
    const FVector StartLocation = Barrel->
        GetSocketLocation(FName("Projectile"));
    // Another nice things about `GetSocketLocation` is that if it cannot find
    // a socket with the supplied name it will fail-over to the Barrel (I can
    // see how falling back (especially if done silently could lead to frustrating
    // debug scenarios)

    // NB: make sure to zero out params since they might return strange values
    // if not velocity can be suggested
    FVector OutLaunchVelocity(0);

    if (UGameplayStatics::SuggestProjectileVelocity(
        this,
        OutLaunchVelocity,
        StartLocation,
        HitLocation,
        LaunchSpeed
        ))
    {
      const auto AimDirection = OutLaunchVelocity.GetSafeNormal();
      const auto Name = GetOwner()->GetName();

      if (!Name.StartsWith("AITank"))
      {
        UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s with velocity %.2f to hit %s "),
             *Name, *AimDirection.ToString(), LaunchSpeed, *HitLocation.ToString());  
      }
      
      
    }
    else
    {
      UE_LOG(LogTemp, Error, TEXT("Cannot suggest projectile velocity"));
    }

    // If you want to use the bDrawDebug option, it's the last arg and can be
    // called as follows
    // const FCollisionResponseParams CollisionResponseParams;
    // const TArray<AActor *> ActorsToIgnore;
    //
    // UGameplayStatics::SuggestProjectileVelocity(
    //   GetWorld(),
    //   OutLaunchVelocity,
    //   StartLocation,
    //   HitLocation,
    //   LaunchSpeed,
    //   false,
    //   0.0,
    //   0.0,
    //   // default
    //   ESuggestProjVelocityTraceOption::TraceFullPath,
    //   CollisionResponseParams,
    //   ActorsToIgnore,
    //   true
    // );

    // UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s with velocity %f and direction %s"),
    // *GetName(), *HitLocation.ToString(), *StartLocation.ToString(), LaunchSpeed, *OutLaunchVelocity.ToString());
  }
  else
  {
    UE_LOG(LogTemp, Error, TEXT("Barrel not set for %s"), *GetName());
  }
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
  Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) const
{
  // work out diff between current rotation and aim direction
  auto BarrelRotator = Barrel->GetForwardVector().Rotation();
  auto AimAsRotator = AimDirection.Rotation();

  auto DeltaRotator = AimAsRotator - BarrelRotator;
  
  // move the barrel the barrel the right amount this frame

  // given a max elevation speed and the frame time
}
