// Copyright 2020 Darren Beukes

#pragma once

#include "CoreMinimal.h"
#include "ObjectMacros.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
  GENERATED_BODY()

private:
  // TODO: Should BlueprintCallable functions be private?
  UFUNCTION(BlueprintCallable, Category = Setup)
  void SetBarrelReference(UTankBarrel* BarrelToSet);

  UFUNCTION(BlueprintCallable, Category = Setup)
  void SetTurretReference(UTankTurret* TurretToSet);


  // TSubclassOf is a type safe way of allowing objects to be set via the editor
  // Superior to UClass* SomeObject; Read more below.
  //https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/TSubclassOf/index.html
  UPROPERTY(EditDefaultsOnly, Category = Setup)
  TSubclassOf<AProjectile> ProjectileBlueprint;
  
  UTankBarrel* Barrel = nullptr;

  UTankAimingComponent* TankAimingComponent = nullptr;

  UPROPERTY(EditDefaultsOnly, Category=Firing)
  float LaunchSpeed = 4000.0; // sensible starting value of 40 m/s

  UPROPERTY(EditDefaultsOnly, Category=Firing)
  double ReloadTimeSeconds = 3.0;

  double LastFireTime = 0.0;
protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

  // UPROPERTY(BlueprintReadOnly, Category=Movement)
  // UTankMovementComponent* TankMovementComponent = nullptr;


public:
  // Sets default values for this pawn's properties
  ATank();
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  // Called to bind functionality to input
  virtual void SetupPlayerInputComponent(
      class UInputComponent* PlayerInputComponent) override;

  void AimAt(FVector HitLocation) const;

  UFUNCTION(BlueprintCallable, Category = Controls)
  void Fire();
};
