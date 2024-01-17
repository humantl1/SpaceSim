// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <unordered_map>
#include "CoreMinimal.h"

namespace MassSystem
{

	typedef double FMass;
	typedef double FVolume;
	typedef double FDensity;

//TODO: Define materials in a data file
UENUM()
enum class EMaterial : uint8
{
	MaterialsStart=0,
	// Metals
	Metals=MaterialsStart,
	Iron = Metals			UMETA(DisplayName = "Iron"),
	Steel					UMETA(DisplayName = "Steel"),
	Aluminium				UMETA(DisplayName = "Aluminium"),
	Copper					UMETA(DisplayName = "Copper"),
	Silver					UMETA(DisplayName = "Silver"),
	Gold					UMETA(DisplayName = "Gold"),
	Platinum				UMETA(DisplayName = "Platinum"),
	// Metaloids
	Metaloids,
	Silicon = Metaloids		UMETA(DisplayName = "Silicon"),
	// Non-metals
	NonMetals,
	Wood = NonMetals		UMETA(DisplayName = "Wood"),
	Plastic					UMETA(DisplayName = "Plastic"),
	Rubber					UMETA(DisplayName = "Rubber"),
	Glass					UMETA(DisplayName = "Glass"),
	// Liquids
	Liquids,
	Water = Liquids			UMETA(DisplayName = "Water"),
	Oil						UMETA(DisplayName = "Oil"),
	// Gases
	Gases,
	Air = Gases				UMETA(DisplayName = "Air"),
	Helium					UMETA(DisplayName = "Helium"),
	// Other
	Other					UMETA(DisplayName = "Other"),
	Unknown = Other			UMETA(DisplayName = "Unknown"),
	OutOfRange				UMETA(DisplayName = "MaterialsStart")
};

typedef TMap<EMaterial, FMass> MaterialDensityMap;

//TODO: Define densities in a data file
//TODO: Get real material densities
MaterialDensityMap materialDensityLookupTable{
	{Iron, 7.874},
	{Steel, 7.874},
	{Aluminium, 2.7},
	{Copper, 8.96},
	{Silver, 10.49},
	{Gold, 19.3},
	{Platinum, 21.45},
	{Silicon, 2.33},
	{Wood, 0.5},
	{Plastic, 1.2},
	{Rubber, 1.5},
	{Glass, 2.5},
	{Water, 1.0},
	{Oil, 0.9},
	{Air, 0.0012},
	{Helium, 0.0001785} };

typedef TMap<MassSystem::EMaterial, MassSystem::FVolume> VolumetricMaterialMap;
typedef TPair<EMaterial, FVolume> VolumetricMaterialPair;

UCLASS()
class SPACESIM_API UMassManager : public UObject
{
public:
	// TODO: Get mass data from data files in constructor
	UMassManager() {};
	~UMassManager() {};

	static UMassManager* GetInstance();
	static bool CalculateIndividualMass(const FVolume volume, const EMaterial material, FMass& outMass);
	static bool CalculateTotalMass(const VolumetricMaterialMap& volumetricMaterialMap, FMass& outMass);

private:
	static UMassManager* mInstance;
};

} // namespace MassSystem