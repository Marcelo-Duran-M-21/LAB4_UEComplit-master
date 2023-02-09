// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenerateCapsule.h"
#include "GenerateCapsuleHelp.generated.h"

/**
 * 
 */
UCLASS()
class UEBRICKS_BREAKER4_API AGenerateCapsuleHelp : public AGenerateCapsule
{
	GENERATED_BODY()

		virtual ACapsuleBasic* FabricarCapsula(FString NombreCapTipo) override;

};
