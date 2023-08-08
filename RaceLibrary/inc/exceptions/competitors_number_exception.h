#pragma once

#include <string>
#include <stdexcept>

namespace simulator_exceptions
{
	class CompetitiorsNumberError : public std::domain_error
	{
	public:
		CompetitiorsNumberError(std::string message="It is impossible to start the race with less than 2 competitors!") 
			: std::domain_error(message) {}
	};
}