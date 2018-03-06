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
		this->passable = false;
		this->type = UNDEFINED_WALL;
	}

	Wall::Wall(const Location& location)
	:Entity(location)
	{
		this->objectType = WALL;
		this->passable = false;

		this->type = UNDEFINED_WALL;
	}

	Wall::Wall(char type)
	:Entity()
	{
		this->objectType = WALL;
		this->passable = false;

		Location location;
		location.x = 0;
		location.y = 0;

		this->location = location;
		this->type = type & 0b00001111;
	}

	Wall::Wall(const Location& location, char type)
	{
		this->objectType = WALL;
		if(type != EMPTY_WALL)
		{
			this->passable = false;
		}

		this->location = location;
		this->type = type;
	}

	Wall::~Wall()
	{
	}
} /* namespace Game */
