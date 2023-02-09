// Copyright Epic Games, Inc. All Rights Reserved.


#include "UEBricks_Breaker4GameModeBase.h"
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "CapsuleBasic.h"
#include "GenerateCapsule.h"
#include "GenerateCapsuleDamage.h"
#include "GenerateCapsuleHelp.h"

AUEBricks_Breaker4GameModeBase::AUEBricks_Breaker4GameModeBase()
{
	// Set this actor to call Tick() every frame. You can turn this off to
	//improve performance if you don't need it.
		PrimaryActorTick.bCanEverTick = true;

}

void AUEBricks_Breaker4GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//creamos un numero randomico para nuestro rango den posibilidades 
	auto probabilityCap = FMath::FRandRange(1, 11);
	// aqui es donde creamos nuestros capsulas 
	if (probabilityCap == 5) {

		AGenerateCapsule* GenerateCapsulaDano = GetWorld()->SpawnActor<AGenerateCapsuleDamage>(AGenerateCapsuleDamage::StaticClass());
		ACapsuleBasic* CapsuleBasic = GenerateCapsulaDano->GetCapsule("BallX2");
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Capsula BallX2 %s"), *CapsuleBasic->ReturnNameCap()));
	}
	else if (probabilityCap < 3) {
		AGenerateCapsule* GenerateCapsulaDano = GetWorld()->SpawnActor<AGenerateCapsuleDamage>(AGenerateCapsuleDamage::StaticClass());
		ACapsuleBasic* CapsuleBasic = GenerateCapsulaDano->GetCapsule("Dano");
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Capsula Dano %s"), *CapsuleBasic->ReturnNameCap()));

	}
	else if (probabilityCap > 9) {
		AGenerateCapsule* GenerateCapsulaHelp = GetWorld()->SpawnActor<AGenerateCapsuleHelp>(AGenerateCapsuleHelp::StaticClass());
		ACapsuleBasic* CapsuleBasic = GenerateCapsulaHelp->GetCapsule("Barrier");
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Capsula Barrier %s"), *CapsuleBasic->ReturnNameCap()));
	}
	else if (probabilityCap == 6) {
		AGenerateCapsule* GenerateCapsulaHelp = GetWorld()->SpawnActor<AGenerateCapsuleHelp>(AGenerateCapsuleHelp::StaticClass());
		ACapsuleBasic* CapsuleBasic = GenerateCapsulaHelp->GetCapsule("Life");
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("Capsula Life %s"), *CapsuleBasic->ReturnNameCap()));

	}
	else if (probabilityCap == 10) {
		AGenerateCapsule* GenerateCapsulaHelp = GetWorld()->SpawnActor<AGenerateCapsuleHelp>(AGenerateCapsuleHelp::StaticClass());
		ACapsuleBasic* CapsuleBasic = GenerateCapsulaHelp->GetCapsule("Growth");
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::White, FString::Printf(TEXT("Capsula Growth %s"), *CapsuleBasic->ReturnNameCap()));

	}
	else if (probabilityCap < 8 && probabilityCap > 6) {
		AGenerateCapsule* GenerateCapsulaHelp = GetWorld()->SpawnActor<AGenerateCapsuleHelp>(AGenerateCapsuleHelp::StaticClass());
		ACapsuleBasic* CapsuleBasic = GenerateCapsulaHelp->GetCapsule("Shield");
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Orange, FString::Printf(TEXT("Capsula Shield %s"), *CapsuleBasic->ReturnNameCap() ));
	}

	

}
// aqui aplicamos el singleton 
void AUEBricks_Breaker4GameModeBase::BeginPlay()
{

	Super::BeginPlay();

	/*FRotator SpawnRotator(0, 0, 0);
	FVector Spawn1(10.0f, 0.0f, 40.0f);
	Brick21 = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn1, FRotator::ZeroRotator);*/
	FVector BrickPosition = FVector(-138, 0, 370);
	FVector Brickpo = FVector(-138, 0, 370);
	FVector BrickSpaceX = FVector(55, 0, 0);

	FVector BrickSpaceZ = FVector(0, 0, -30);
	FVector BrickPosition1 = FVector(-140, 0, 380);
	int Colu = 0;

	//Capsule1 = GetWorld()->SpawnActor<ACapsuleBasic>(ACapsuleBasic::StaticClass(), BrickPosition1, FRotator::ZeroRotator);

	while (Colu <5) {		//for (int Colu = 0; Colu < 4; Colu++) {

		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("hola")));

		for (int fila = 0; fila < 6; fila++) {

			Brick21 = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), BrickPosition, FRotator::ZeroRotator);
			//Capsule1 = GetWorld()->SpawnActor<ACapsuleBasic>(ACapsuleBasic::StaticClass(), BrickPosition, FRotator::ZeroRotator);
			BrickPosition = BrickPosition + BrickSpaceX;



		}
		 
		Brickpo += BrickSpaceZ;
		BrickPosition = Brickpo;
		
		Colu++;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("hola")));
	
}
	
				//Brick21=GetWorld()->SpawnActor<ABrick>(BrickPosition, BrickRotation);
		
		
	/*	FVector Loca=FVector(-150)
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				FVector BrickPosition = FVector(-50, 0,150);
		        FRotator BrickRotation = FRotator(0, 0, 0);
				GetWorld()->SpawnActor<ABrick>(BrickPosition, BrickRotation);
				FVector BrickPosition = FVector(i * 30, 0, j * 33);
				
			}
		}*/


		//Create 4 Inventory
		for (int i = 0; i <= 2; i++)
		{
			APaddle* SpawnedPaddle = GetWorld()->SpawnActor<APaddle>(APaddle::StaticClass());
			if (SpawnedPaddle)
			{
				//If the Spawn succeeds, set the Spawned inventory to the local one
				//and log the success string
				Paddle = SpawnedPaddle;
				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s has been created"), *Paddle->GetName()));
			}
		}

	
}

	
