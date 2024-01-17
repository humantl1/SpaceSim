// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassManager.h"
#include "HeatManager.h"
#include "ShipComponent.generated.h"

UCLASS(Abstract)
class UShipComponent
{
	GENERATED_BODY()

public:
	// state
	virtual void UpdateState() = 0;

	// mass
	virtual bool UpdateMaterials(const MassSystem::VolumetricMaterialPair& volumetricMaterialpair);
	inline virtual const MassSystem::VolumetricMaterialMap& GetMaterials() const { return mMaterialVolumes; };
	inline virtual const MassSystem::FMass GetTotalMass() const { return mTotalMass; };

	// heat

	virtual const double GetHeatGeneration() const { return mHeatGeneration; };
	virtual const double GetContainedHeat() const { return mContainedHeat; };

protected:
	MassSystem::FMass mTotalMass;
	MassSystem::VolumetricMaterialMap mMaterialVolumes;
	double mHeatGeneration;
	double mContainedHeat;

	virtual bool UpdateTotalMass();
	virtual void UpdateHeat(HeatSystem::Heat newHeat);
	virtual void UpdateHeatGeneration(HeatSystem::Heat heatModification);
};
