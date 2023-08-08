#pragma once

#include "air_vehicle.h"

namespace vehicles
{
	class Eagle : public AirVehicle
	{
	public:
		Eagle() : AirVehicle("Eagle", 8) {}
		virtual ~Eagle() {}

	private:
		double getReductonFactor(double distance) const override;
	};
}