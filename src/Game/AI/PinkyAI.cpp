/*
 * PinkyAI.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: Astrid
 */

#include "PinkyAI.h"
#include "../Control/Gamemanager.h"

namespace Game
{

	PinkyAI::PinkyAI()
	: AI()
	{
		this->scatterTarget.x = 0;
		this->scatterTarget.y = 0;
	}

	PinkyAI::PinkyAI(const PinkyAI& ai)
	: AI(ai)
	{
	}

	PinkyAI::~PinkyAI()
	{
	}

	PinkyAI& PinkyAI::operator=(const PinkyAI& ai)
	{
		if(this != &ai)
		{
			AI::operator=(ai);
		}
		return *this;
	}

	Util::Location PinkyAI::getChaseTarget(const Util::Location& loc) const noexcept
	{
		Util::Location target = Gamemanager::getInstance().getPacman()->getLocation();
		Util::Direction direction = Gamemanager::getInstance().getPacman()->getDirection();

		for(int i = 0; i<4; i++)
		{
			target += direction;
		}


		return target;
	}

} /* namespace Game */
