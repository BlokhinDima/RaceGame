#pragma once

#include "air_vehicle.h"

namespace vehicles
{
	class MagicCarpet : public AirVehicle
	{
	public:
		MagicCarpet() : AirVehicle("Magic Carpet", 10) {}
		virtual ~MagicCarpet() {}

	private:
		double getReductonFactor(double distance) const override;
	};
}