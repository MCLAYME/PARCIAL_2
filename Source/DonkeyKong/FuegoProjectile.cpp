// Fill out your copyright notice in the Description page of Project Settings.


#include "FuegoProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"



// Sets default values
AFuegoProjectile::AFuegoProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetStaticMesh(MeshAsset.Object);
	RootComponent = Mesh;


	// Asignar colisión
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Mesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	/*
	// Cargar el material de fuego
	static ConstructorHelpers::FObjectFinder<UMaterial> FuegoMaterial(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));
	if (FuegoMaterial.Succeeded())
	{
		Mesh->SetMaterial(0, FuegoMaterial.Object);
	}

	// Cargar el efecto de partículas y sonido
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleEffectFinder(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (ParticleEffectFinder.Succeeded())
	{
		ParticleEffect = ParticleEffectFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<USoundBase> SoundFinder(TEXT("SoundWave'/Game/Path/To/Sound_Fuego.Sound_Fuego'"));
	if (SoundFinder.Succeeded())
	{
		CollisionSound = SoundFinder.Object;
	}*/

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
	MovementComponent->InitialSpeed = 3000.f;
	MovementComponent->MaxSpeed = 3000.f;
}

// Called when the game starts or when spawned
void AFuegoProjectile::BeginPlay()
{
	Super::BeginPlay();
	// Configurar el evento de colisión
	//Mesh->OnComponentBeginOverlap.AddDynamic(this, &AFuegoProjectile::OnOverlap);
}

// Called every frame
void AFuegoProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFuegoProjectile::Disparar()
{
	UE_LOG(LogTemp, Warning, TEXT("Disparando proyectil de fuego!"));


}

/*void AFuegoProjectile::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	if (OtherActor && (OtherActor != this))
	{
		// Reproducir sonido de colisión
		UGameplayStatics::PlaySoundAtLocation(this, CollisionSound, GetActorLocation());
		// Instanciar el efecto de partículas
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleEffect, GetActorLocation(), FRotator::ZeroRotator, true);
		Destroy();
	}
}
*/
