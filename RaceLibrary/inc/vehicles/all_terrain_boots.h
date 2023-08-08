#pragma once

#include "ground_vehicle.h"

namespace vehicles
{
	class AllTerrainBoots : public GroundVehicle
	{
	public:
		AllTerrainBoots() : GroundVehicle("All Terrain Boots", 6, 60) {}
		virtual ~AllTerrainBoots() {}

	private:
		double calculateRecoveryTime(double distance) const override;
	};
}