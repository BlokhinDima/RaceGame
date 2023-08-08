#include <stdexcept>

#include "factories.h"
#include "race.h"
#include "air_race.h"
#include "ground_race.h"
#include "camel.h"
#include "racing_camel.h"
#include "centaur.h"
#include "all_terrain_boots.h"
#include "magic_carpet.h"
#include "eagle.h"
#include "broom.h"
#include "simulator_exception.h"

races::Race* factories::createRace(RacesTypes type)
{
	switch (type)
	{
	case RacesTypes::MIXED_RACE:
		return new races::Race();

	case RacesTypes::GROUND_RACE:
		return new races::GroundRace();

	case RacesTypes::AIR_RACE:
		return new races::AirRace();

	default:
		throw simulator_exceptions::SimulatorError("Undefined race type!");
	}
}

vehicles::Vehicle* factories::createVehicle(VehiclesModels model)
{
	switch (model)
	{
	case VehiclesModels::CAMEL:
		return new vehicles::Camel();

	case VehiclesModels::RACING_CAMEL:
		return new vehicles::RacingCamel();

	case VehiclesModels::CENTAUR:
		return new vehicles::Centaur();

	case VehiclesModels::ALL_TERRAIN_BOOTS:
		return new vehicles::AllTerrainBoots();

	case VehiclesModels::MAGIC_CARPET:
		return new vehicles::MagicCarpet();

	case VehiclesModels::EAGLE:
		return new vehicles::Eagle();

	case VehiclesModels::BROOM:
		return new vehicles::Broom();

	default:
		throw simulator_exceptions::SimulatorError("Undefined vehicle type!");
	}
}
