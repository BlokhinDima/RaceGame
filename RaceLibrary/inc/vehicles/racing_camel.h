#pragma once

#include "ground_vehicle.h"

namespace vehicles
{
	class RacingCamel : public GroundVehicle
	{
	public:
		RacingCamel() : GroundVehicle("Racing Camel", 40, 10) {}
		virtual ~RacingCamel() {}

	private:
		double calculateRecoveryTime(double distance) const override;
	};
}