/*
 * Ghost.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */


#include "Ghost.h"
using namespace std;

namespace Game
{
	Ghost::Ghost()
	:Entity()
	{
		this->objectType = GHOST;

		this->type = Blinky;
		this->fear = false;
	}

	Ghost::Ghost(const Ghost& g)
	:Entity(g)
	{
		this->objectType = GHOST;
		this->type = g.type;
		this->fear = g.fear;
	}

	Ghost::Ghost(GhostType type)
	:Entity()
	{
		this->objectType = GHOST;

		this->type = type;
		this->fear = false;
	}

	Ghost::Ghost(Location location, GhostType type)
	:Entity(location)
	{
		this->objectType =GHOST;

		this->type = type;
		this->fear = false;
	}

	Ghost::~Ghost()
	{
	}

	GhostType Ghost::getType()
	{
		return this->type;
	}

	void Ghost::setType(GhostType type)
	{
		this->type = type;
	}
}

