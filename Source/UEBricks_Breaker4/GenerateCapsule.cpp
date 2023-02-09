// Fill out your copyright notice in the Description page of Project Settings.


#include "GenerateCapsule.h"

// Sets default values
AGenerateCapsule::AGenerateCapsule()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGenerateCapsule::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGenerateCapsule::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//
}

ACapsuleBasic* AGenerateCapsule::GetCapsule(FString TipoCapsule)
{
	
	
	ACapsuleBasic* capsule = FabricarCapsula(TipoCapsule);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("Fabricando capsula %s"), *capsule->GetName()));

	capsule->Generate();
	return capsule;
}
