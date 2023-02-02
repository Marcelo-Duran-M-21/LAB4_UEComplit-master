// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsuleBasic.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"

// Sets default values
ACapsuleBasic::ACapsuleBasic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>CapsuleMesh(TEXT("StaticMesh'/Game/Meshes/SM_Brick.SM_Brick'"));

	// in this part we create un subobject 
	SM_Capsule = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Capsule"));
	SM_Capsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Capsule->SetStaticMesh(CapsuleMesh.Object);

	CapsuleCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("CapsuleCollision"));
	//BoxCollision->SetBoxExtent(FVector(2.0f, 10.0f, 50.0f));


	RootComponent = CapsuleCollision;

	SM_Capsule->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	CapsuleCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	static ConstructorHelpers::FObjectFinder<UMaterialInterface>Material(TEXT("MaterialInstanceConstant'/Game/Materials/M_BrickGreen.M_BrickGreen'"));
	if (Material.Succeeded()) {
		auto* MaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, Material.Object);
		SM_Capsule->SetMaterial(0, MaterialInstance);
	}
}

// Called when the game starts or when spawned
void ACapsuleBasic::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACapsuleBasic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

