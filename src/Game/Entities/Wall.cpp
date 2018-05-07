/*
 * Wall.cpp
 *
 *  Created on: 4 mrt. 2018
 *      Author: Astrid
 */

#include <iostream>
#include "Wall.h"
using namespace std;

namespace Game
{
	Wall::Wall()
	:Entity()
	{
		this->passable = false;
		this->type = UNDEFINED_WALL;
		this->value = 0;
	}

	Wall::Wall(const Wall& w)
	:Entity(w)
	{
		this->type = w.type;
		this->value = w.value;
	}

	Wall::Wall(const Util::Location& location)
	:Entity(location)
	{
		this->passable = false;
		this->type = UNDEFINED_WALL;
		this->value = 0;
	}

	Wall::Wall(char type)
	:Entity()
	{
		Util::Location location;
		location.x = 0;
		location.y = 0;

		this->location = location;
		this->type = type & 0b00001111;
		if(this->type != EMPTY_WALL && this->type != DOT_WALL)
		{
			this->passable = false;
		}

		this->value = 0;
	}

	Wall::Wall(const Util::Location& location, char type)
	{
		if(type != EMPTY_WALL && type != DOT_WALL)
		{
			this->passable = false;
		}

		this->location = location;
		this->type = type;
		this->value = 0;
	}

	Wall::Wall(const Util::Location& location, char type, int value)
	{
		if(type != EMPTY_WALL && type != DOT_WALL && type != POWER_PELLET)
		{
			this->passable = false;
		}

		this->location = location;
		this->type = type;
		this->value = value;
	}

	Wall& Wall::operator=(const Wall& w)
	{
		if(this != &w)
		{
			Entity::operator =(w);
			this->type = w.type;
			this->value = w.value;
		}

		return *this;
	}

	Wall::~Wall()
	{
	}

	void Wall::setType(char type) noexcept
	{
		this->type = type;
		if(this->type == EMPTY_WALL || this->type == DOT_WALL || this->type == POWER_PELLET)
		{
			this->passable = true;
		}
		else
		{
			this->passable = false;
		}
	}

	char Wall::getType() const noexcept
	{
		return this->type;
	}

	void Wall::setValue(int value) noexcept
	{
		this->value = value;
	}

	int Wall::getValue() const noexcept
	{
		return this->value;
	}
} /* namespace Game */
