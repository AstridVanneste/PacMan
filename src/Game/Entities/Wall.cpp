/*
 * Wall.cpp
 *
 *  Created on: 4 mrt. 2018
 *      Author: Astrid
 */

#include "Wall.h"

namespace Game
{
	Wall::Wall()
	{
		this->objectType = WALL;

		this->type = UNDEFINED_WALL;
	}

	Wall::Wall(char type)
	{
		this->objectType = WALL;

		this->type = type & 0b00001111;
	}

	Wall::~Wall()
	{
		// TODO Auto-generated destructor stub
	}
} /* namespace Game */
