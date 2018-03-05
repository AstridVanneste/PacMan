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
		this->objectType = ENTITY;

		this->location.x = 0;
		this->location.y = 0;
	}

	Entity::Entity(const Location& location)
	{
		this->objectType = ENTITY;

		this->location.x = location.x;
		this->location.y = location.y;
	}

	Entity::~Entity()
	{
	}

	void Entity::setObjectType(char type)
	{
		this->objectType = type;
	}

	char Entity::getObjectType()
	{
		return this->objectType;
	}

}

