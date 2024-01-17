// Fill out your copyright notice in the Description page of Project Settings.


#include "MassManager.h"

using namespace MassSystem;

UMassManager* UMassManager::GetInstance()
{
	if (nullptr == mInstance)
	{
		mInstance = NewObject<UMassManager>();
		mInstance->AddToRoot(); // Prevent garbage collection
	}

	return mInstance;
}

bool UMassManager::CalculateIndividualMass(const FVolume volume, const EMaterial material, FMass& outMass)
{
	FMass calculatedMass = 0.0f;

	const FMass* materialMass = materialDensityLookupTable.Find(material);
	if (nullptr == materialMass)
	{
		UE_LOG(LogTemp, Error, TEXT("Material %i not found in density lookup table"), material);
		return false;
	}

	calculatedMass = volume * *materialMass;

	return true;
}

bool UMassManager::CalculateTotalMass(const VolumetricMaterialMap& volumetricMaterialMap, FMass& outMass)
{
	FMass totalMass = 0.0f;

	for (auto& volumetricMaterialPair : volumetricMaterialMap)
	{
		const FMass* materialMass = materialDensityLookupTable.Find(volumetricMaterialPair.Key);
		if (nullptr == materialMass)
		{
			UE_LOG(LogTemp, Error, TEXT("Material %i not found in density lookup table"), volumetricMaterialPair.Key);
			return false;
		}

		totalMass += volumetricMaterialPair.Value * *materialMass;
	}

	outMass = totalMass;

	return true;
}
