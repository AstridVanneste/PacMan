/*
 * Ghost.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#include "Ghost.h"

Ghost::Ghost()
{
	this->type = Blinky;
	this->fear = false;
}

Ghost::Ghost(GhostType type)
{
	this->type = type;
	this->fear = false;
}

Ghost::~Ghost()
{
	// TODO Auto-generated destructor stub
}

GhostType Ghost::getType()
{
	return this->type;
}

void Ghost::setType(GhostType type)
{
	this->type = type;
}

