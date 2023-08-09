#pragma once

#include "race.h"
#include "vehicle.h"
#include "vehicles_models.h"
#include "races_factory.h"
#include "vehicles_factory.h"


namespace race_simulators {

	class RaceSimulator
	{
	public:
		~RaceSimulator();
		void setRaceType(races_factory::RacesTypes type);
		void setRaceDistance(double distance);
		void simulateRace();
		void printRaceInfo() const;
		void registerVehicle(const vehicles_models::VehiclesModels model);
		void printLeadershipTable() const;
		int getParticipantsNumber() const;

	private:
		races::Race* race = nullptr;
		const races::LeadershipListEntry* leadership_list = nullptr;
	};
}
