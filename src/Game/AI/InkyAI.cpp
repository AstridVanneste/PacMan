/*
 * InkyAI.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: Astrid
 */

#include "InkyAI.h"
#include "../Control/Gamemanager.h"

namespace Game
{
	InkyAI::InkyAI()
	: AI()
	{
		this->scatterTarget = Gamemanager::getInstance().getArena()->getSize();
	}

	InkyAI::InkyAI(const InkyAI& ai)
	: AI(ai)
	{
	}

	InkyAI::~InkyAI()
	{
	}

	InkyAI& InkyAI::operator=(const InkyAI& ai)
	{
		if(this != &ai)
	{

	AI::operator=(ai);
	}
		if(this != &ai)
		{
			AI::operator=(ai);
		}
		return *this;
	}

	Util::Location InkyAI::getChaseTarget(const Util::Location& loc) const noexcept
	{
		Util::Location pacman = Gamemanager::getInstance().getPacman()->getLocation();
			Util::Location target = pacman;

			if(this->getDistance(pacman, loc) > 8)
			{
				target = this->scatterTarget;
			}
			return target;
	}

} /* namespace Game */
