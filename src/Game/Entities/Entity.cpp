/*
 * Entity.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: Astrid
 */

#include "Entity.h"
#include <iostream>
using namespace std;

namespace Game
{
	Entity::Entity()
	{
		this->passable = true;

		this->location.x = 0;
		this->location.y = 0;
	}

	Entity::Entity(const Entity& e)
	{
		this->passable = e.passable;
		this->location = e.location;
	}

	Entity::Entity(const Util::Location& location)
	{
		this->passable = true;
		this->location = location;
	}

	Entity::~Entity()
	{
	}

	Entity& Entity::operator =(const Entity& e)
	{
		if(this != &e)
		{
			this->location = e.location;
		}
		return *this;
	}

	bool Entity::isPassable() const noexcept
	{
		return this->passable;
	}

	Util::Location Entity::getLocation() const noexcept
	{
		return this->location;
	}

	void Entity::setLocation(const Util::Location& location) noexcept
	{
		this->location = location;
	}

}

