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
		this->x = 0;
		this->y = 0;
	}

	Entity::Entity(int x, int y, string image)
	{
		this->x = x;
		this->y = y;
		this->image = image;
	}

	Entity::~Entity()
	{
	}
}

