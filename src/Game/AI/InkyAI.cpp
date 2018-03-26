/*
 * InkyAI.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: Astrid
 */

#include "InkyAI.h"
#include "../Gamemanager.h"

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

} /* namespace Game */
