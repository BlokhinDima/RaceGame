#pragma once

#include "race.h"
#include "vehicle.h"
#include "factories.h"

namespace race_simulators {

	class RaceSimulator
	{
	public:
		~RaceSimulator();
		void setRaceType(factories::RacesTypes type);
		void setRaceDistance(double distance);
		void simulateRace();
		void printRaceInfo() const;
		void registerVehicle(factories::VehiclesModels model);
		void printLeadershipTable() const;
		int getParticipantsNumber() const;

	private:
		races::Race* race = nullptr;
		const races::LeadershipListEntry* leadership_list = nullptr;
	};
}
