// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IProjectileAdapter.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "HieloProjectile.generated.h"

UCLASS()
class DONKEYKONG_API AHieloProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHieloProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Método para manejar la colisió
//	UFUNCTION()

//	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

	virtual void Disparar(); // Implementación del método de la interfaz

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* MovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	class UParticleSystem* ParticleEffect; // Efecto de partículas al colisionar

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	class USoundBase* CollisionSound; // Sonido al colisionar
	
};
