#pragma once

#include "vehicle.h"

namespace vehicles
{
	class GroundVehicle : public Vehicle
	{
	public:
		GroundVehicle(std::string name, int speed, int movement_time_until_rest) 
			: Vehicle(VehicleType::GROUND, name, speed), move_time_until_rest(movement_time_until_rest) {}
		virtual ~GroundVehicle() {}
		double calculateTravelTime(double distance) const override;

	protected:
		int move_time_until_rest{};
		virtual double calculateRecoveryTime(double distance) const = 0;
		int calculateStopsNumber(double distance) const;
	};
}