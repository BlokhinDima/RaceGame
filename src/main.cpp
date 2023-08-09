#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>


#include "races_factory.h"
#include "vehicles_factory.h"
#include "race_simulator.h"
#include "registration_exception.h"
#include "simulator_exception.h"
#include "distance_exception.h"


enum ProgramStatus
{
	OK,
	ERROR
};


void printRacesMenu()
{
	std::cout << std::endl; 
	std::cout << "1. Ground vehicles race" << std::endl;
	std::cout << "2. Air vehicles race" << std::endl;
	std::cout << "3. Mixed vehicles race" << std::endl;
}


void printVehiclesRegistrationMenu()
{
	std::cout << std::endl;
	std::cout << "1. Camel" << std::endl;
	std::cout << "2. Racing Camel" << std::endl;
	std::cout << "3. Centaur" << std::endl;
	std::cout << "4. All Terrian Boots" << std::endl;
	std::cout << "5. Magic Carpet" << std::endl;
	std::cout << "6. Eagle" << std::endl;
	std::cout << "7. Broom" << std::endl;
	std::cout << "0. End registration" << std::endl;
}


void printEndMenu()
{
	std::cout << std::endl;
	std::cout << "1. Start new race" << std::endl;
	std::cout << "2. Quit" << std::endl;
}


int handleInput()
{
	int choice = 0;
	std::cout << "Enter value: ";
	std::cin >> choice;
	while (std::cin.fail())
	{
		std::cout << std::endl << "Wrong input! Try again." << std::endl;
		std::cout << "Enter value: ";
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin >> choice;
	}
	return choice;
}


void registerVehicles(race_simulators::RaceSimulator& race_simulator)
{
	try 
	{
		for (;;)
		{
			std::cout << std::endl 
				<< "Select vehicle model or enter 0 to end registration: ";
			printVehiclesRegistrationMenu();
			int input = handleInput();

			if (input == 0) { break; }

			race_simulator.registerVehicle(
				static_cast<vehicles_models::VehiclesModels>(input - 1)
			);
			race_simulator.printRaceInfo();
		}
	}
	catch (const simulator_exceptions::RegistrationError& ex)
	{
		std::cout << std::endl << ex.what() << std::endl;
		registerVehicles(race_simulator);
	}
	catch (const simulator_exceptions::SimulatorError& ex)
	{
		std::cout << std::endl << ex.what() << std::endl;
		registerVehicles(race_simulator);
	}
}

void processRaceTypeSelection(race_simulators::RaceSimulator& race_simulator)
{
	try 
	{
		std::cout << std::endl <<"Select race type: ";
		printRacesMenu();
		int race_type = handleInput();
		race_simulator.setRaceType(static_cast<races_factory::RacesTypes>(race_type - 1));
	}
	catch (const simulator_exceptions::SimulatorError& ex)
	{
		std::cout << std::endl << ex.what() << std::endl;
		processRaceTypeSelection(race_simulator);
	}
}

void processDistanceInput(race_simulators::RaceSimulator& race_simulator)
{
	try
	{
		std::cout << std::endl << "Enter race distance (must be positive). ";
		double distance = handleInput();
		race_simulator.setRaceDistance(distance);
	}
	catch (const simulator_exceptions::DistanceValueError& ex)
	{
		std::cout << std::endl << ex.what() << std::endl;
		processDistanceInput(race_simulator);
	}
}

void processVehiclesRegistration(race_simulators::RaceSimulator& race_simulator)
{
	for (;;)
	{
		std::cout << std::endl
			<< "At least 2 vehicles must be registered to start race. "
			<< "Participants registered: " << race_simulator.getParticipantsNumber()
			<< std::endl;

		std::cout << "1. Register vehicle" << std::endl;
		if (race_simulator.getParticipantsNumber() >= 2)
		{
			std::cout << "2. Start race" << std::endl;
		}

		int input = handleInput();
		if (input == 1)
		{
			registerVehicles(race_simulator);
		}
		else if (input == 2)
		{
			break;
		}
		else
		{
			std::cout << "Wrong option! Try again.";
		}
	}
}

bool askForRestart()
{
	int choice = 0;
	for(;;)
	{
		std::cout << std::endl << "Do you want to start new race?";
		printEndMenu();
		choice = handleInput();
		if (choice == 1)
		{
			return true;
		}
		else if (choice == 2)
		{
			return false;
		}
		else
		{
			std::cout << std::endl << "Wrong option! Try again." << std::endl;
			continue;
		}
	}
}

int main()
{
	using namespace race_simulators;
	std::cout << "Welcome to race simulator!" << std::endl;
	race_simulators::RaceSimulator race_simulator;
	
	for (;;)
	{
		processRaceTypeSelection(race_simulator);
		processDistanceInput(race_simulator);
		processVehiclesRegistration(race_simulator);
		race_simulator.simulateRace();
		race_simulator.printLeadershipTable();
		bool choice = askForRestart();
		if (choice)
		{
			continue;
		}
		else
		{
			break;
		}
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();

	return OK;
}
