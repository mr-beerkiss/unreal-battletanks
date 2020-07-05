// Copyright 2020 Darren Beukes

#include "Tank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values
ATank::ATank()
{
  // Set this pawn to call Tick() every frame.  You can turn this off to improve
  // performance if you don't need it.
  PrimaryActorTick.bCanEverTick = false;

  TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
  TankAimingComponent->SetBarrelReference(BarrelToSet);
}

// Called when the game starts or when spawned
void ATank::BeginPlay() { Super::BeginPlay(); }

// Called every frame
void ATank::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
  Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::AimAt(FVector HitLocation) const
{
  TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}
