// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PaddlePlayerController.generated.h"

/**
 * 
 */
class ABall;

UCLASS()
class UEBRICKS_BREAKER4_API APaddlePlayerController : public APlayerController
{
	GENERATED_BODY()
		APaddlePlayerController();

	UFUNCTION()
		virtual void SetupInputComponent() override;

	protected:
		virtual void BeginPlay() override;
		void MoveHorizontal(float AxisValue);
		//new 
		void MoveVer(float _VerAxisValue);
		void Lanch();
		
		
		//aqui ya estamos spawnwadno nuestro ball pimero creando pero nuestro template de tipoa ABall 
		UPROPERTY(EditAnywhere)
			TSubclassOf<ABall> BallObj;

		ABall* MyBall;
		FVector SpawnLocation = FVector(10.0f, 0.0f, 40.0f);
		FRotator SpawnRotator = FRotator(32.0f, 90.0f, 8.0f);
		FActorSpawnParameters SpawnInfo;

		public:
			void SpawnNewBall();


};
