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
	:MovingEntity()
	{
		this->objectType = GHOST;

		this->type = BLINKY;
		this->fear = false;
	}

	Ghost::Ghost(const Ghost& g)
	:MovingEntity(g)
	{
		this->objectType = GHOST;
		this->type = g.type;
		this->fear = g.fear;
	}

	Ghost::Ghost(GhostType type)
	:MovingEntity()
	{
		this->objectType = GHOST;

		this->type = type;
		this->fear = false;
	}

	Ghost::Ghost(Location location, GhostType type)
	:MovingEntity(location)
	{
		this->objectType =GHOST;

		this->type = type;
		this->fear = false;
	}

	Ghost::~Ghost()
	{
	}

	Ghost& Ghost::operator=(const Ghost& g)
	{
		if(this != &g)
		{
			MovingEntity::operator =(g);
			this->type = g.type;
			this->fear = g.fear;
		}

		return *this;
	}

	const GhostType Ghost::getType() noexcept
	{
		return this->type;
	}

	void Ghost::setType(GhostType type) noexcept
	{
		this->type = type;
	}
}

