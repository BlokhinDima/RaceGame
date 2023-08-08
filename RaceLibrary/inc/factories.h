#pragma once

#include "race.h"
#include "vehicle.h"

namespace factories
{
	enum class RacesTypes
	{
		GROUND_RACE = 0,
		AIR_RACE,
		MIXED_RACE
	};

	enum class VehiclesModels
	{
		CAMEL = 0,
		RACING_CAMEL,
		CENTAUR,
		ALL_TERRAIN_BOOTS,
		MAGIC_CARPET,
		EAGLE,
		BROOM,
		VEHICLE_COUNT
	};

	/*
	const char* VehicleToString(VehiclesModels model)
	{
		static const char* vehicleNames[] =
		{
			"Camel",
			"Racing Camel",
		};

		return vehicleNames[(int)model];
	}
	*/

	races::Race* createRace(const RacesTypes type);
	vehicles::Vehicle* createVehicle(const VehiclesModels model);
}