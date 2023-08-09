#pragma once

#include <string>

#include "vehicle.h"
#include "vehicles_factory.h"
#include "vehicles_models.h"

namespace races
{
	struct LeadershipListEntry
	{
		std::string vehicle_name{};
		double race_score{};
	};

	class Race
	{
	public:
		Race(const std::string& name="Mixed Race") : name(name) {};
		virtual ~Race();
		const std::string& getName() const { return name; }
		void setDistance(double distance);
		double getDistance() const { return distance; } 
		int getParticipantsNumber() const { return participants_number; }
		void registerVehicle(const vehicles_models::VehiclesModels model);
		const vehicles::Vehicle** getRegisteredVehicles() { return registered_vehicles; }
		const LeadershipListEntry* runRace();

	protected:
		const std::string name;
		double distance = 0;
		int participants_number = 0;
		const vehicles::Vehicle** registered_vehicles = nullptr;
		LeadershipListEntry* leadership_list = nullptr;

		void deleteVehiclesStorage();
		void deleteVehicles();
		void deleteLeadershipList();
		void sortVehiclesByTravelTime();
		void createLeadershipList();
		bool isVehicleRegistered(const vehicles::Vehicle* vehicle) const;
		virtual bool isVehicleCompatible(const vehicles::Vehicle* vehicle) const;
	};
}
