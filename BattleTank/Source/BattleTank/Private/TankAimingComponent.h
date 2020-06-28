// Copyright 2020 Darren Beukes

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

private:
        UStaticMeshComponent* Barrel = nullptr;
 

public:	
        void AimAt(FVector HitLocation, float LaunchSpeed) const;
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
        void MoveBarrelTowards(FVector AimDirection) const;
};
