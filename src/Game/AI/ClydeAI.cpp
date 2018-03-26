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
	cout << "CLYDE AI created, TARGET = " << this->scatterTarget << endl;
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

} /* namespace Game */
