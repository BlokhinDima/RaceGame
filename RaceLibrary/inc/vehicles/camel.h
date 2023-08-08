#pragma once

#include "ground_vehicle.h"

namespace vehicles
{
	class Camel : public GroundVehicle
	{
	public:
		Camel() : GroundVehicle("Camel", 10, 30) {}
		virtual ~Camel() {}

	private:
		double calculateRecoveryTime(double distance) const override;
	};
}