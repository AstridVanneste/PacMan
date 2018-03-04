/*
 * Entity.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: Astrid
 */

#include "Entity.h"
namespace Game
{
	Entity::Entity()
	{
		this->location.x = 0;
		this->location.y = 0;
	}

	Entity::Entity(Location location)
	{
		this->location.x = location.x;
		this->location.y = location.y;
	}

	Entity::~Entity()
	{
	}
}

