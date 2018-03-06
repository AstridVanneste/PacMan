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
		this->objectType = ENTITY;

		this->location.x = 0;
		this->location.y = 0;
	}

	Entity::Entity(const Entity& e)
	{
		this->objectType = e.objectType;
		this->location = e.location;
	}

	Entity::Entity(const Location& location)
	{
		this->objectType = ENTITY;

		this->location = location;
	}

	Entity::~Entity()
	{
	}

	Entity& Entity::operator =(const Entity& e)
	{
		if(this != &e)
		{
			this->objectType = e.objectType;
			this->location = e.location;
		}
		return *this;
	}

	void Entity::setObjectType(char type)
	{
		this->objectType = type;
	}

	char Entity::getObjectType()
	{
		cout << "checking object type" << endl;
		cout << "Object type: " << +this->objectType << endl;
		return this->objectType;
	}

}

