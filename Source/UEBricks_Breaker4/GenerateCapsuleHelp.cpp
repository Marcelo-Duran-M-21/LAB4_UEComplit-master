// Fill out your copyright notice in the Description page of Project Settings.


#include "GenerateCapsuleHelp.h"
#include "CapsuleBarrierO.h"
#include "CapsuleLife.h"
#include "CapsuleShield.h"
#include "BasicGrowthPaddle.h"

ACapsuleBasic* AGenerateCapsuleHelp::FabricarCapsula(FString NombreCapTipo)
{
	if (NombreCapTipo.Equals("Life")) {
		return GetWorld()->SpawnActor<ACapsuleLife>(ACapsuleLife::StaticClass());
	}
	else if (NombreCapTipo.Equals("Barrier")) {
		return GetWorld()->SpawnActor<ACapsuleBarrierO>(ACapsuleBarrierO::StaticClass());
	}
	else if (NombreCapTipo.Equals("Shield")) {
		return GetWorld()->SpawnActor<ACapsuleShield>(ACapsuleShield::StaticClass());
	}
	else if (NombreCapTipo.Equals("Growth")) {
		return GetWorld()->SpawnActor<ABasicGrowthPaddle>(ABasicGrowthPaddle::StaticClass());
	}
	return nullptr;
}
