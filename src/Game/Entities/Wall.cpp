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
	:Entity()
	{
		this->objectType = WALL;

		this->type = UNDEFINED_WALL;
	}

	Wall::Wall(const Location& location)
	:Entity(location)
	{
		this->objectType = WALL;
		this->type = UNDEFINED_WALL;
	}

	Wall::Wall(char type)
	:Entity()
	{
		this->objectType = WALL;

		Location location;
		location.x = 0;
		location.y = 0;

		this->location = location;
		this->type = type & 0b00001111;
	}

	Wall::Wall(const Location& location, char type)
	{
		this->objectType = WALL;
		this->location = location;
		this->type = type;
	}

	Wall::~Wall()
	{
	}
} /* namespace Game */
