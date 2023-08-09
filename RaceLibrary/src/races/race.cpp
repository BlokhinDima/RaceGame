#include <iostream>
#include <string>

#include "race.h"
#include "vehicle.h"
#include "vehicles_factory.h"
#include "distance_exception.h"
#include "competitors_number_exception.h"
#include "registration_exception.h"

races::Race::~Race()
{
	deleteLeadershipList();
	deleteVehicles();
	deleteVehiclesStorage();
}

void races::Race::deleteVehiclesStorage()
{
	if (registered_vehicles) 
	{
		delete[] registered_vehicles;
		registered_vehicles = nullptr;
	}
}

void races::Race::deleteVehicles()
{
	if (registered_vehicles)
	{
		for (int i = 0; i < participants_number; ++i)
		{
			delete registered_vehicles[i];
		}
	}
}

void races::Race::deleteLeadershipList()
{
	if (leadership_list)
	{
		delete[] leadership_list;
		leadership_list = nullptr;
	}
}

void races::Race::setDistance(double distance)
{
	if (distance <= 0)
	{
		throw simulator_exceptions::DistanceValueError();
	}
	this->distance = distance;
}

void races::Race::registerVehicle(const vehicles_models::VehiclesModels model)
{
	vehicles::Vehicle* vehicle = vehicles_factory::createVehicle(model);

	if (isVehicleRegistered(vehicle))
	{
		vehicles_factory::deleteVehicle(vehicle);
		throw simulator_exceptions::RegistrationError(
			"This type of vehicle already registred!"
		);
	}

	if (!isVehicleCompatible(vehicle))
	{
		vehicles_factory::deleteVehicle(vehicle);
		throw simulator_exceptions::RegistrationError(
			"Attemp to registrate incompatible vehicle type!"
		);
	}

	const int new_participants_number = participants_number + 1;
	const vehicles::Vehicle** temp = new const vehicles::Vehicle*[new_participants_number];

	for (int i = 0; i < new_participants_number - 1; ++i)
	{
		temp[i] = registered_vehicles[i];
	}
	temp[new_participants_number - 1] = vehicle;
	deleteVehiclesStorage();
	registered_vehicles = temp;// LEAK
	participants_number += 1;
}

const races::LeadershipListEntry* races::Race::runRace()
{
	if (participants_number < 2)
	{
		throw simulator_exceptions::CompetitiorsNumberError();
	}
	sortVehiclesByTravelTime();
	createLeadershipList();
	return leadership_list;
}

void races::Race::sortVehiclesByTravelTime()
{
	bool swapped = false;

	for (int i = 0; i < participants_number - 1; ++i)
	{
		swapped = false;

		for (int j = 0; j < participants_number - i - 1; ++j)
		{
			double current_vehicle_score = registered_vehicles[j]->calculateTravelTime(distance);
			double next_vehicle_score = registered_vehicles[j + 1]->calculateTravelTime(distance);

			if (current_vehicle_score > next_vehicle_score)
			{
				const vehicles::Vehicle* temp = registered_vehicles[j];
				registered_vehicles[j] = registered_vehicles[j + 1];
				registered_vehicles[j + 1] = temp;
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}

void races::Race::createLeadershipList()
{
	deleteLeadershipList();
	leadership_list = new LeadershipListEntry[participants_number];

	for (int i = 0; i < participants_number; ++i)
	{
		leadership_list[i].vehicle_name = registered_vehicles[i]->getName();
		leadership_list[i].race_score = registered_vehicles[i]->calculateTravelTime(distance);
	}
}

bool races::Race::isVehicleRegistered(const vehicles::Vehicle* vehicle) const
{
	for (int i = 0; i < participants_number; ++i)
	{
		if (registered_vehicles[i]->getName() == vehicle->getName())
		{
			return true;
		}
	}
	return false;
}

bool races::Race::isVehicleCompatible(const vehicles::Vehicle* vehicle) const
{
	return true;
}