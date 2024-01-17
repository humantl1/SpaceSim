// Fill out your copyright notice in the Description page of Project Settings.


#include "HeatManager.h"

using namespace HeatSystem;

UHeatManager* UHeatManager::GetInstance()
{
	if (nullptr == mInstance)
	{
		mInstance = NewObject<UHeatManager>();
		mInstance->AddToRoot(); // Prevent garbage collection
	}

	return mInstance;
}

Heat UHeatManager::UpdateHeat(Heat currentHeat, Heat newHeat)
{
	return currentHeat + newHeat;
}

Heat UHeatManager::UpdateHeateGeneration(Heat currentHeatGeneration, Heat updatedHeateGeneration)
{
	return currentHeatGeneration + updatedHeateGeneration;
}
