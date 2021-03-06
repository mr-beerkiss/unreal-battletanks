// Copyright 2020 Darren Beukes


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
  // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
  // off to improve performance if you don't need them.
  PrimaryComponentTick.bCanEverTick = true;
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
        LaunchSpeed,
        false,
        0,
        0,
        ESuggestProjVelocityTraceOption::DoNotTrace
        ))
    {
      const auto AimDirection = OutLaunchVelocity.GetSafeNormal();
      MoveTurretTowards(AimDirection);
      MoveBarrelTowards(AimDirection);
    }
  }
  else
  {
    UE_LOG(LogTemp, Error, TEXT("Barrel not set for %s"), *GetName());
  }
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
  Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
  Turret = TurretToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) const
{
  if (!Barrel)
  {
    UE_LOG(LogTemp, Error, TEXT("Barrel reference has not been set!"));
    return; 
  }

  // work out diff between current rotation and aim direction
  auto BarrelRotator = Barrel->GetForwardVector().Rotation();
  auto AimAsRotator = AimDirection.Rotation();

  auto DeltaRotator = AimAsRotator - BarrelRotator;

  Barrel->Elevate(DeltaRotator.Pitch);
}

void UTankAimingComponent::MoveTurretTowards(FVector AimDirection) const
{
  if (!Turret)
  {
    UE_LOG(LogTemp, Error, TEXT("Turret reference has not been set!"));
    return;
  }
  auto TurretRotator = Turret->GetForwardVector().Rotation();
  auto AimAsRotator = AimDirection.Rotation();

  auto DeltaRotator = AimAsRotator - TurretRotator;

  const auto Name = GetOwner()->GetName();

  Turret->Rotate(DeltaRotator.Yaw);
}
