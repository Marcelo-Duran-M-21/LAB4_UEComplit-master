// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"
#include "Ball.h"


// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.  improve=mejorar 
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>BrickMessAsset(TEXT("StaticMesh'/Game/Meshes/SM_Brick.SM_Brick'"));

	// in this part we create un subobject 
	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Brick->SetStaticMesh(BrickMessAsset.Object);
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	//BoxCollision->SetBoxExtent(FVector(2.0f, 10.0f, 50.0f));
	

	RootComponent = BoxCollision;
	SM_Brick->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	BoxCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	// agegamos nuestos valores predefinidos de la rotacion de movimiento de bricks
	PitchValue = 0.f;
	YawValue = 0.f;
	RollValue = 0.f;

	

	static ConstructorHelpers::FObjectFinder<UMaterialInterface>Material(TEXT("MaterialInstanceConstant'/Game/Materials/M_BrickRed.M_BrickRed'"));
	if (Material.Succeeded()) {
		auto* MaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, Material.Object);
		SM_Brick->SetMaterial(0, MaterialInstance);
	}
	/*SM_Brick->SetWorldLocation(FVector(10.f, 0.f, 400.f));
	RootComponent = SM_Brick;*/

}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();

	//UWorld* World = GetWorld();
	//if (World) {
	//	FVector Loca(30.f, 0.f, 200.f);
	//	FRotator Rota(0, 0, 0);
	//	World->SpawnActor<ABrick>(Loca, Rota);
	//}
	//spawnBrick();

	//UClass* ObjectToSpawn = ABrick::StaticClass();

	////Posición y rotación donde se spawneará el objeto
	//FVector SpawnLocation(2.f, 0.0f, 10.f);
	//FRotator SpawnRotation(0.0f, 0.0f, 0.0f);

	////Spawnear el objeto en el mundo
	//ABrick* SpawnedObject = GetWorld()->SpawnActor<ABrick>(ObjectToSpawn, SpawnLocation, SpawnRotation);

	//spawnBrick();
	//FVector Apa(0.f, 0.f, 0.f);
	//ABrick* brick = NewObject<ABrick>();
	//brick->SM_Brick->SetWorldLocation(Apa);



}

void ABrick::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult)
{

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);
	

		if (OtherActor->ActorHasTag("Ball")) {
			ABall* MyBall = Cast<ABall>(OtherActor);

			FVector BallVelocity = MyBall->GetVelocity();
			BallVelocity *= (SpeedModifierOnBounce - 1.0f);

			MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);
			

			this->Destroy();

		
		}
		
		


}


void ABrick::DestroyBrick()
{
	this->Destroy();

}

// Called every frame   
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// FQuat nos crea un punto de flotacion en 3d 
	FQuat QuatRotation = FQuat(FRotator(PitchValue, YawValue, RollValue));
	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}

void ABrick::spawnBrick()
{
	
	

	

		////Referencia a la clase del objeto a spawnear
		//UClass* ObjectToSpawn = ABrick::StaticClass();

		////Posición y rotación donde se spawneará el objeto
		//FVector SpawnLocation(2.f, 0.0f, 10.f);
		//FRotator SpawnRotation(0.0f, 0.0f, 0.0f);

		////Spawnear el objeto en el mundo
		//ABrick* SpawnedObject = GetWorld()->SpawnActor<ABrick>(ObjectToSpawn, SpawnLocation, SpawnRotation);


	/*	for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				FVector BrickPosition = FVector(i * 10, j * 10, 20);
				FRotator BrickRotation = FRotator(12, 0, 0);
				GetWorld()->SpawnActor<ABrick>(BrickPosition, BrickRotation);
			}
		}
	*/
}

