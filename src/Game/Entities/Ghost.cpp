/*
 * Ghost.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */


#include "Ghost.h"
#include "../AI/BlinkyAI.h"
#include "../AI/PinkyAI.h"
#include "../AI/InkyAI.h"
#include "../AI/ClydeAI.h"
#include <iostream>
using namespace std;

namespace Game
{
	Ghost::Ghost()
	:MovingEntity()
	{
		this->objectType = GHOST;
		this->type = BLINKY;
		this->createAI();
	}

	Ghost::Ghost(const Ghost& g)
	:MovingEntity(g)
	{
		this->objectType = GHOST;
		this->type = g.type;
		this->createAI();
	}

	Ghost::Ghost(GhostType type)
	:MovingEntity()
	{
		this->objectType = GHOST;
		this->type = type;
		this->createAI();
	}

	Ghost::Ghost(Util::Location location, GhostType type)
	:MovingEntity(location)
	{
		this->objectType = GHOST;
		this->type = type;

		this->createAI();
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
			this->createAI();
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

	void Ghost::createAI() noexcept
	{
		switch(this->type)
		{
		case BLINKY:
			//cout << "BLINKY made" << endl;
			this->ai = make_unique<BlinkyAI>();
			break;
		case PINKY:
			//cout << "PINKY made" << endl;
			this->ai = make_unique<PinkyAI>();
			break;
		case INKY:
			//cout << "INKY made" << endl;
			this->ai = make_unique<InkyAI>();
			break;
		case CLYDE:
			//cout << "CLYDE made" << endl;
			this->ai = make_unique<ClydeAI>();
			break;
		}
	}
}

