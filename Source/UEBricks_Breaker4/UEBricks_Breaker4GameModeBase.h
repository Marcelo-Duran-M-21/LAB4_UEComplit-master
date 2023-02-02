// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UEBricks_Breaker4GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UEBRICKS_BREAKER4_API AUEBricks_Breaker4GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AUEBricks_Breaker4GameModeBase();
protected:
	//The Inventory of this Actor
	UPROPERTY()
		// creamos la clase del singleton o inventory del libro unreal engine 5 game programing  desing patterns
		class APaddle* Paddle;
	class ABrick* Brick21;

	class ACapsuleBasic* Capsule1;

		UPROPERTY(VisibleAnywhere)
			class ABrick* Brick;
		UPROPERTY(VisibleAnywhere)
			class ABrick* Brick1;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

