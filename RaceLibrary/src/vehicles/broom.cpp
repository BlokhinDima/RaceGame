#include "broom.h"

double vehicles::Broom::getReductonFactor(double distance) const
{
	return (static_cast<int>(distance) / 1000) * 0.01;
}
