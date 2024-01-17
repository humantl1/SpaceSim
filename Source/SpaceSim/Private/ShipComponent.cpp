// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipComponent.h"

bool UShipComponent::UpdateMaterials(const MassSystem::VolumetricMaterialPair& volumetricMaterialpair)
{
	MassSystem::EMaterial material = volumetricMaterialpair.Key;

	MassSystem::FVolume volume = volumetricMaterialpair.Value;

	const UEnum* materialEnumPtr = StaticEnum<MassSystem::EMaterial>();
	FName materialName = materialEnumPtr->GetNameByValue(static_cast<int64>(material));
	if (materialEnumPtr->IsValidEnumValue(static_cast<int8>(material)) == false)
	{
		UE_LOG(LogTemp, Error, TEXT("Material %s not a valid enum"), materialName.ToString());
		return false;
	}

	if (mMaterialVolumes.Contains(material))
	{
		mMaterialVolumes[material] += volume;
	}
	else
	{
		mMaterialVolumes.Add(material, volume);
	}

	if (false == UpdateTotalMass())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to update total mass for material[%s], volume[%d]"), materialName.ToString(), volume);
		return false;
	}

	return true;
}

bool UShipComponent::UpdateTotalMass()
{
	if (false == MassSystem::UMassManager::CalculateTotalMass(mMaterialVolumes, mTotalMass))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to calculate total mass. Last total mass[%d]."), mTotalMass);
		return false;
	}

	return true;
}

void UShipComponent::UpdateHeat(HeatSystem::Heat newHeat)
{
	mContainedHeat = HeatSystem::UHeatManager::UpdateHeat(mContainedHeat, newHeat);
}

void UShipComponent::UpdateHeatGeneration(HeatSystem::Heat heatModification)
{
	mHeatGeneration = HeatSystem::UHeatManager::UpdateHeateGeneration(mHeatGeneration, heatModification);
}
