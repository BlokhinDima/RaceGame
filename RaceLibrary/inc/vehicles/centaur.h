#pragma once

#include "ground_vehicle.h"

namespace vehicles
{
	class Centaur : public GroundVehicle
	{
	public:
		Centaur() : GroundVehicle("Centaur", 15, 8) {}
		virtual ~Centaur() {}

	private:
		double calculateRecoveryTime(double distance) const override;
	};
}