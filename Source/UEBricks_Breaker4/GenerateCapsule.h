// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CapsuleBasic.h"
#include "GenerateCapsule.generated.h"

UCLASS()
class UEBRICKS_BREAKER4_API AGenerateCapsule : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGenerateCapsule();


	virtual ACapsuleBasic* FabricarCapsula(FString NombreCapTipo)PURE_VIRTUAL(AGenerateCapsule::FabricarCapsula, return nullptr;);

	ACapsuleBasic* GetCapsule(FString TipoCapsule);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
