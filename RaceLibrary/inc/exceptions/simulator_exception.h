#pragma once

#include <string>
#include <stdexcept>

namespace simulator_exceptions
{
	class SimulatorError : public std::domain_error
	{
	public:
		SimulatorError(std::string message) : std::domain_error(message) {}
	};
}