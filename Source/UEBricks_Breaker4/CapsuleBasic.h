// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CapsuleBasic.generated.h"
class UBoxComponent;

UCLASS()
class UEBRICKS_BREAKER4_API ACapsuleBasic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACapsuleBasic();
	



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//nombre de la capsula
	FString NameCap;
	float su;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* SM_Capsule;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* CapsuleCollision;
	//modificamos el 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UMaterialInterface* SM_Material;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// sirve para generar nueva capsula

	virtual void Generate();


	// implementamos el metodos   

	FString ReturnNameCap() { return NameCap; }

};
