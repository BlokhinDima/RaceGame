#include "vehicle.h"
#include "ground_vehicle.h"

double vehicles::GroundVehicle::calculateTravelTime(double distance) const
{
	const double recovery_time = calculateRecoveryTime(distance);
	return distance / speed + recovery_time;
}

int vehicles::GroundVehicle::calculateStopsNumber(double distance) const
{
	return static_cast<int>(distance) / speed / move_time_until_rest;
}
