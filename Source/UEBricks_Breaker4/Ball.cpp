// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	RootComponent = SM_Ball;

	SM_Ball->SetSimulatePhysics(true);
	SM_Ball->SetEnableGravity(false);
	SM_Ball->SetConstraintMode(EDOFMode::XZPlane);
	SM_Ball->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	
	
	SM_Ball->SetCollisionProfileName(TEXT("PhysicsActor"));
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement "));
	//new implementation de mi projectile // velocidad inicial projectile
	ProjectileMovement->InitialSpeed = 18.f;
	// agregamos maxima velocidad 
	ProjectileMovement->MaxSpeed = 1000.f;
	//projectile sigue la velocidad de rotacion 
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	//agregamos velocidad cuando el projectile choca en eje z
	ProjectileMovement->Velocity.Z = 500.f;

	ProjectileMovement->Bounciness = 3.1f;
	ProjectileMovement->Friction = 0.0f;
	ProjectileMovement->Velocity.X = 12.0f;

	
	
	
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ABall::Launch()
{
	if (!BallLaunched) {
		SM_Ball->AddImpulse(FVector(200.0f, 60.0f, 200.f), FName(), true);
		//agregamos impulso angular para el projectile
		SM_Ball->AddAngularImpulse(FVector(90.f));
		//agregamosiluminacion de campo de distancia 
		SM_Ball->bAffectDistanceFieldLighting = false;
		// agregamos torque al projectile
		SM_Ball->AddTorque(FVector(23.f), FName(), true);
		SM_Ball->bReplicatePhysicsToAutonomousProxy = true;
		
		BallLaunched = true;
		
		
	}

}


UStaticMeshComponent* ABall::GetBall()
{
	return SM_Ball;
}

