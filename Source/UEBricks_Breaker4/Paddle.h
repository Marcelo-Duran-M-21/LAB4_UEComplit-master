// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Paddle.generated.h"
class UFloatingPawnMovement;
UCLASS()
class UEBRICKS_BREAKER4_API APaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APaddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Paddle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UFloatingPawnMovement* FloatingMovement;

	UPROPERTY(EditAnywhere, Category = "Campo Game")
		float FieldHight;
	UPROPERTY(EditAnywhere, Category = "Campo Game")
		float FieldWidth;
	FVector CurrentLocation;
	
	APaddle* Instance;


	int numPaddle=0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void MoveHorizontal(float AxisValue);



	//Agregamos un nuevo movimiento de muesetro padel del eje vertical respecto a z
	virtual void MoveVer(float _VerAxisValue);
};
