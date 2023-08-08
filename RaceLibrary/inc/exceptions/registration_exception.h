#pragma once

#include <string>
#include <stdexcept>

namespace simulator_exceptions
{
	class RegistrationError : public std::domain_error
	{
	public:
		RegistrationError(std::string message) : std::domain_error(message) {}
	};
}