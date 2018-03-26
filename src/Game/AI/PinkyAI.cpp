/*
 * PinkyAI.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: Astrid
 */

#include "PinkyAI.h"

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

} /* namespace Game */
