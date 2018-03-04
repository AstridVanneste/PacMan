/*
 * Entity.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: Astrid
 */

#include "Entity.h"

Entity::Entity()
{
	this->x = 0;
	this->y = 0;
}

Entity::Entity(int x, int y)
{
	this->x = x;
	this->y = y;
}

Entity::~Entity()
{
}

