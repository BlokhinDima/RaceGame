#pragma once

#include "air_vehicle.h"

namespace vehicles
{
	class Broom : public AirVehicle
	{
	public:
		Broom() : AirVehicle("Broom", 20) {}
		virtual ~Broom() {}

	private:
		double getReductonFactor(double distance) const override;
	};
}