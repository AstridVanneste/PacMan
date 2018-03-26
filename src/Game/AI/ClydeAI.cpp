/*
 * ClydeAI.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: Astrid
 */

#include "ClydeAI.h"
#include "../Gamemanager.h"

namespace Game
{

ClydeAI::ClydeAI()
: AI()
{
	this->scatterTarget = Gamemanager::getInstance().getArena()->getSize();
	this->scatterTarget.y = 0;
	//cout << "CLYDE AI created, TARGET = " << this->scatterTarget << endl;
}

ClydeAI::ClydeAI(const ClydeAI& ai)
: AI(ai)
{
}

ClydeAI::~ClydeAI()
{
}

ClydeAI& ClydeAI::operator=(const ClydeAI& ai)
{
	if(this != &ai)
	{
		AI::operator=(ai);
	}
	return *this;
}

const Util::Location ClydeAI::getChaseTarget(const Util::Location& loc) noexcept
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
