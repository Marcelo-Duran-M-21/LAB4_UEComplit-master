// Fill out your copyright notice in the Description page of Project Settings.


#include "GenerateCapsuleDamage.h"
#include "CapsuleBallX2.h"
#include "CapsuleDano.h"

ACapsuleBasic* AGenerateCapsuleDamage::FabricarCapsula(FString NombreCapTipo)
{

	if (NombreCapTipo.Equals("BallX2")) {
		return GetWorld()->SpawnActor<ACapsuleBallX2>(ACapsuleBallX2::StaticClass());
	}
	else if (NombreCapTipo.Equals("Dano")) {
		return GetWorld()->SpawnActor<ACapsuleDano>(ACapsuleDano::StaticClass());
	}
	return nullptr;
}
