// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePlayerController.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "Paddle.h"
#include "Ball.h"


APaddlePlayerController::APaddlePlayerController()
{

}

void APaddlePlayerController::BeginPlay()
{
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);
	SpawnNewBall();

}
void APaddlePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);

	InputComponent->BindAxis("MoveHorizontal", this, &APaddlePlayerController::MoveHorizontal);

	//configuramos la entrada de component para nuestro movimiento Vertical
	InputComponent->BindAxis("MoveVer", this, &APaddlePlayerController::MoveVer);
	InputComponent->BindAction("Launch", IE_Pressed, this, &APaddlePlayerController::Lanch);



}

void APaddlePlayerController::MoveHorizontal(float AxisValue)
{
	auto MyPawn = Cast<APaddle>(GetPawn());

	if (MyPawn) {
		MyPawn->MoveHorizontal(AxisValue);
	}

}// agregamos el movimiento y declaramos en nuestro player controller

void APaddlePlayerController::MoveVer(float _VerAxisValue)
{
	auto MyPawn = Cast<APaddle>(GetPawn());
	if (MyPawn) {
		MyPawn->MoveVer( _VerAxisValue);
	}
}

void APaddlePlayerController::Lanch()
{
	MyBall->Launch();
}





void APaddlePlayerController::SpawnNewBall()
{
	if (!MyBall) {
		MyBall = nullptr;
		
	}
	
	
	if (BallObj) {
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotator, SpawnInfo);
	} 

}
