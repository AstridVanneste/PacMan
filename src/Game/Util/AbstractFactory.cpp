/*
 * AbstractFactory.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#include "../Util/AbstractFactory.h"

namespace Game
{
	AbstractFactory::AbstractFactory()
	{
	}

	AbstractFactory::~AbstractFactory()
	{
	}

	AbstractFactory& AbstractFactory::operator=(const AbstractFactory& ah)
	{
		return *this;
	}
}
