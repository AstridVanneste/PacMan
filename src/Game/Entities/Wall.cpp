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
		this->objectType = WALL;
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
		this->objectType = WALL;
		this->passable = false;
		this->type = UNDEFINED_WALL;
		this->value = 0;
	}

	Wall::Wall(char type)
	:Entity()
	{
		this->objectType = WALL;


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
		this->objectType = WALL;
		if(type != EMPTY_WALL && type != DOT_WALL)
		{
			this->passable = false;
		}

		this->location = location;
		this->type = type;
		this->value = 0;
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

	void Wall::setType(char type) noexcept
	{
		cout << "setting wall type from " << +this->type << " to " << +type << endl;
		this->type = type;
		if(this->type != EMPTY_WALL && this->type != DOT_WALL)
		{
			this->passable = true;
		}
		else
		{
			this->passable = false;
		}
	}

	const char Wall::getType() noexcept
	{
		return this->type;
	}

	Wall::~Wall()
	{
	}
} /* namespace Game */
