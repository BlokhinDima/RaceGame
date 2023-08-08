#include <iostream>
#include <climits>

#include "race_simulator.h"
#include "race.h"
#include "vehicle.h"
#include "factories.h"
#include "simulator_exception.h"
#include "registration_exception.h"
#include "distance_exception.h"

race_simulators::RaceSimulator::~RaceSimulator()
{
	delete race; // function
}

int race_simulators::RaceSimulator::getParticipantsNumber() const
{
	if (race)
	{
		return race->getParticipantsNumber();
	}
	return 0;
}

void race_simulators::RaceSimulator::printRaceInfo() const
{
	std::cout << race->getName() << ". Distance: " << race->getDistance() << std::endl;

	std::cout << "Registered vehicles: ";
	const vehicles::Vehicle** registered_vehicles = race->getRegisteredVehicles();
	int vehicles_number = getParticipantsNumber();
	for (int i = 0; i < vehicles_number; ++i)
	{
		std::cout << registered_vehicles[i]->getName();
		if (i != vehicles_number - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

void race_simulators::RaceSimulator::registerVehicle(factories::VehiclesModels model)
{
	vehicles::Vehicle* vehicle = factories::createVehicle(model);
	race->registerVehicle(vehicle);
	std::cout << vehicle->getName() + " registered!" << std::endl;
}

void race_simulators::RaceSimulator::setRaceType(factories::RacesTypes type)
{
	// delete prev race
	race = factories::createRace(type);
}

void race_simulators::RaceSimulator::simulateRace()
{
	leadership_list = race->runRace();
}

void race_simulators::RaceSimulator::setRaceDistance(double distance)
{
	race->setDistance(distance);
}

void race_simulators::RaceSimulator::printLeadershipTable() const
{
	std::cout << std::endl << "Race result: " << std::endl;
	const int vehicles_number = getParticipantsNumber();

	for (int i = 0; i < vehicles_number; ++i)
	{
		races::LeadershipListEntry entry = leadership_list[i];
		std::cout << (i + 1) << ". "
			<< entry.vehicle_name << ". "
			<< "Result: " << entry.race_score
			<< std::endl;
	}
}
