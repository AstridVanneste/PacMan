/*
 * Ghost.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */


#include "Ghost.h"
#include "../../Settings/Config.h"
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
		this->type = BLINKY;
		if(Settings::Config::getInstance().keyExists(Settings::GHOST_SPEED))
		{
			this->speed = Settings::Config::getInstance().getValueOfKey<int>(Settings::GHOST_SPEED);
			//cout << "EMPTY CONSTRUCTOR: Ghost speed set to " << this->speed << endl;
		}
		this->createAI();
	}

	Ghost::Ghost(const Ghost& g)
	:MovingEntity(g)
	{
		this->type = g.type;
		this->createAI();
	}

	Ghost::Ghost(GhostType type)
	:MovingEntity()
	{
		if(Settings::Config::getInstance().keyExists(Settings::GHOST_SPEED))
		{
			this->speed = Settings::Config::getInstance().getValueOfKey<int>(Settings::GHOST_SPEED);
			//cout << "COPY CONSTRUCTOR: Ghost speed set to " << this->speed << endl;
		}
		this->type = type;
		this->createAI();
	}

	Ghost::Ghost(Util::Location location, GhostType type)
	:MovingEntity(location)
	{
		if(Settings::Config::getInstance().keyExists(Settings::GHOST_SPEED))
		{
			this->speed = Settings::Config::getInstance().getValueOfKey<int>(Settings::GHOST_SPEED);
			//cout << "REGULAR CONSTRUCTOR: Ghost speed set to " << this->speed << endl;
		}
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

	GhostType Ghost::getType() const noexcept
	{
		return this->type;
	}

	void Ghost::setType(GhostType type) noexcept
	{
		this->type = type;
	}

	bool Ghost::update() noexcept
	{
		this->nextDirection = this->ai->getNewDirection(this->location, this->direction);
		return MovingEntity::update();
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

	void Ghost::setMode(const AImode& mode) noexcept
	{
		this->ai->setMode(mode);
	}

	void Ghost::toggleMode() noexcept
	{
		this->ai->toggleMode();
	}

	AImode Ghost::getMode() const noexcept
	{
		return this->ai->getMode();
	}

	void Ghost::respawn() noexcept
	{
		MovingEntity::respawn();
		this->ai->toggleMode();
	}
}

