/*
 * Ghost.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */


#include "Ghost.h"
#include <iostream>
using namespace std;

namespace Game
{
	Ghost::Ghost()
	:MovingEntity()
	{
		this->objectType = GHOST;

		this->type = BLINKY;
	}

	Ghost::Ghost(const Ghost& g)
	:MovingEntity(g)
	{
		this->objectType = GHOST;
		this->type = g.type;
		//this->ai = make_unique(g.ai.get());
		this->ai = make_unique<AI>();
	}

	Ghost::Ghost(GhostType type)
	:MovingEntity()
	{
		this->objectType = GHOST;
		this->type = type;
		this->ai = make_unique<AI>();
	}

	Ghost::Ghost(Util::Location location, GhostType type)
	:MovingEntity(location)
	{
		this->objectType = GHOST;
		this->type = type;

		this->ai = make_unique<AI>();
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
			//this->ai = g.ai;
			this->ai = make_unique<AI>();
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

	bool Ghost::update() noexcept
	{
		if(MovingEntity::update())
		{
			this->direction = this->ai->getNewDirection(this->location, this->direction);
			//cout << "NEW DIRECTION for ghost " << this->type << " = " << this->direction << endl;
			return true;
		}
		return false;
	}
}

