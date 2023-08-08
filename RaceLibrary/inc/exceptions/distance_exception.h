#pragma once

#include <string>
#include <stdexcept>

namespace simulator_exceptions
{
	class DistanceValueError : public std::domain_error
	{
	public:
		DistanceValueError(std::string message="It is impossible to start the race with zero or negative distance!") 
			: std::domain_error(message) {}
	};
}