/*
 * BlinkyAI.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: Astrid
 */

#include <iostream>
#include "BlinkyAI.h"
#include "../Gamemanager.h"

namespace Game
{

BlinkyAI::BlinkyAI()
: AI()
{
	Util::Location target = Gamemanager::getInstance().getArena()->getSize();
	target.x = 0;
	this->scatterTarget = target;
	//cout << "BLINKY AI created, TARGET = " << this->scatterTarget << endl;
}

BlinkyAI::BlinkyAI(const BlinkyAI& ai)
: AI(ai)
{
}

BlinkyAI::~BlinkyAI()
{
}

BlinkyAI& BlinkyAI::operator =(const BlinkyAI& ai)
{
	if(this != &ai)
	{
		AI::operator=(ai);
	}
	return *this;
}

const Util::Location BlinkyAI::getChaseTarget(const Util::Location& loc) noexcept
{
	return Gamemanager::getInstance().getPacman()->getLocation();
}

} /* namespace SDL */
