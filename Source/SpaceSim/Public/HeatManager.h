// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

namespace HeatSystem
{

typedef double Heat;

UCLASS()
class SPACESIM_API UHeatManager : public UObject
{
public:
	UHeatManager() {};
	~UHeatManager() {};

	static UHeatManager* GetInstance();
	static Heat UpdateHeat(Heat currentHeat, Heat newHeat);
	static Heat UpdateHeateGeneration(Heat currentHeatGeneration, Heat updatedHeateGeneration);

private:
	static UHeatManager* mInstance;
};

} // namespace HeatSystem