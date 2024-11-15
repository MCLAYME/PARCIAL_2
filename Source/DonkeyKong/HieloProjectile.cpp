// Fill out your copyright notice in the Description page of Project Settings.


#include "HieloProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AHieloProjectile::AHieloProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetStaticMesh(MeshAsset.Object);
	RootComponent = Mesh;

	/* Cargar el material de hielo
	static ConstructorHelpers::FObjectFinder<UMaterial> HieloMaterial(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'"));
	if (HieloMaterial.Succeeded())
	{
		Mesh->SetMaterial(0, HieloMaterial.Object);
	}

	// Cargar el efecto de partículas y sonido
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleEffectFinder(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Sparks.P_Sparks'"));
	if (ParticleEffectFinder.Succeeded())
	{
		ParticleEffect = ParticleEffectFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<USoundBase> SoundFinder(TEXT("SoundCue'/Game/StarterContent/Audio/Starter_Music_Cue.Starter_Music_Cue'"));
	if (SoundFinder.Succeeded())
	{
		CollisionSound = SoundFinder.Object;
	}*/
	// Asignar colisión
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Mesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
	MovementComponent->InitialSpeed = 3000.f;
	MovementComponent->MaxSpeed = 3000.f;
}

// Called when the game starts or when spawned
void AHieloProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	// Configurar el evento de colisión
//	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AHieloProjectile::OnOverlap);
}

// Called every frame
void AHieloProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
/*
void AHieloProjectile::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	if (OtherActor && (OtherActor != this))
	{
		// Reproducir sonido de colisión
		UGameplayStatics::PlaySoundAtLocation(this, CollisionSound, GetActorLocation());
		// Instanciar el efecto de partículas
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleEffect, GetActorLocation(), FRotator::ZeroRotator, true);
		Destroy();
	}
}*/


void AHieloProjectile::Disparar()
{
	// Lógica para el proyectil de hielo
	UE_LOG(LogTemp, Warning, TEXT("Disparando proyectil de hielo!"));
}

