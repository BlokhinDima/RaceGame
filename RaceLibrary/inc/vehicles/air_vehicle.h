#pragma once

#include "vehicle.h"

namespace vehicles
{
	class AirVehicle : public Vehicle
	{
	public:
		AirVehicle(std::string const& name, int speed) : Vehicle(VehicleType::AIR, name, speed) {}
		virtual ~AirVehicle() {}
		double calculateTravelTime(double distance) const override;

	protected:
		double calculateReducedDistance(double distance) const;
		virtual double getReductonFactor(double distance) const = 0;
	};
}