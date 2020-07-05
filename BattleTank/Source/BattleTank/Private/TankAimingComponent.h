// Copyright 2020 Darren Beukes

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward declarations
class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

private:
        UTankBarrel* Barrel = nullptr;
 

public:	
        void AimAt(FVector HitLocation, float LaunchSpeed) const;
	void SetBarrelReference(UTankBarrel* BarrelToSet);
        void MoveBarrelTowards(FVector AimDirection) const;
};
