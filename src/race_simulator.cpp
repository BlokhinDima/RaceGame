#include <iostream>
#include <climits>

#include "race_simulator.h"
#include "race.h"
#include "vehicle.h"
#include "races_factory.h"
#include "vehicles_factory.h"
#include "simulator_exception.h"
#include "registration_exception.h"
#include "distance_exception.h"

race_simulators::RaceSimulator::~RaceSimulator()
{
	races_factory::deleteRace(race);
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

void race_simulators::RaceSimulator::registerVehicle(vehicles_models::VehiclesModels model)
{
	race->registerVehicle(model);
	const char* vehicle_name = vehicles_models::vehicleToString(model);
	std::cout << std::endl << vehicle_name << " registered!" << std::endl;
}

void race_simulators::RaceSimulator::setRaceType(races_factory::RacesTypes type)
{
	races_factory::deleteRace(race);
	race = races_factory::createRace(type);
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
