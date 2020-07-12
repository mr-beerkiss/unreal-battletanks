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
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
  GENERATED_BODY()

public:
  // Sets default values for this pawn's properties
  ATank();

  UFUNCTION(BlueprintCallable, Category = Setup)
  void SetBarrelReference(UTankBarrel* BarrelToSet);

  UFUNCTION(BlueprintCallable, Category = Setup)
  void SetTurretReference(UTankTurret* TurretToSet);

  UFUNCTION(BlueprintCallable, Category = Controls)
  void Fire();

  // TSubclassOf is a type safe way of allowing objects to be set via the editor
  // Superior to UClass* SomeObject; Read more below.
  //https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/TSubclassOf/index.html
  UPROPERTY(EditAnywhere, Category = Setup)
  TSubclassOf<AProjectile> Projectile;
  
  UTankBarrel* Barrel = nullptr;
  
protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

  // UPROPERTY(EditAnywhere)
  UTankAimingComponent* TankAimingComponent = nullptr;

  UPROPERTY(EditAnywhere, Category=Firing)
  float LaunchSpeed = 4000.0; // sensible starting value of 40 m/s

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  // Called to bind functionality to input
  virtual void SetupPlayerInputComponent(
      class UInputComponent* PlayerInputComponent) override;

  void AimAt(FVector HitLocation) const;
};
