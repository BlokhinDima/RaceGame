#include "vehicle.h"
#include "air_vehicle.h"


double vehicles::AirVehicle::calculateTravelTime(double distance) const
{
	return calculateReducedDistance(distance) / speed;
}

double vehicles::AirVehicle::calculateReducedDistance(double distance) const
{
	return (1 - getReductonFactor(distance)) * distance;
}