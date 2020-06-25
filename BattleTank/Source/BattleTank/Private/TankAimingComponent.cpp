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


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation) const
{
  if (Barrel)
  {
    
    UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"),
    *GetName(), *HitLocation.ToString(), *Barrel->GetComponentLocation().ToString());  
  }
  else
  {
    UE_LOG(LogTemp, Error, TEXT("Barrel not set for %s"), *GetName());
  }
  
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
  // UE_LOG(LogTemp, Warning, TEXT("Well done you set the Barrel via a Blueprint"));
  Barrel = BarrelToSet;
}

