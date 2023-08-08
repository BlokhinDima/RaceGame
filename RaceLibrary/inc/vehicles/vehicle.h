#pragma once

#include <string>

namespace vehicles {

	enum class VehicleType
	{
		UNKNOWN,
		GROUND,
		AIR,
	};

	class Vehicle
	{
	public:
		Vehicle(VehicleType type=VehicleType::UNKNOWN, std::string const& name="Vehicle", int speed=1)
			: vehicle_type(type), name(name), speed(speed) {}
		virtual ~Vehicle() {}
		const std::string& getName() const { return name; }
		const VehicleType getType() const { return vehicle_type; }
		virtual double calculateTravelTime(double distance) const = 0;

	protected:
		VehicleType vehicle_type;
		const std::string name;
		unsigned int speed;
	};
}