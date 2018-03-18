/*
 * AI.cpp
 *
 *  Created on: 18 mrt. 2018
 *      Author: Astrid
 */

#include "AI.h"

namespace Game
{

	AI::AI()
	{
		this->mode = SCATTER;
	}

	AI::AI(const AI& ai)
	{
		this->mode = ai.mode;
	}

	AI::~AI()
	{
	}

	const Direction AI::getNewDirection(shared_ptr<Arena> arena) noexcept
	{
		Location target;
		switch(mode)
		{
		case SCATTER:
			target = this->getScatterTarget(arena);
			break;
		case CHASE:
			target = this->getChaseTarget(arena);
			break;
		case FRIGHTENED:
			target = this->getFrightenedTarget(arena);
			break;
		}

		return UP;
	}

	const Location AI::getScatterTarget(shared_ptr<Arena> arena) noexcept
	{
		Location target = arena->getPacman()->getLocation();

		return target;
	}

	const Location AI::getChaseTarget(shared_ptr<Arena> arena) noexcept
	{
		Location target = arena->getPacman()->getLocation();

		return target;
	}

	const Location AI::getFrightenedTarget(shared_ptr<Arena> arena) noexcept
	{
		Location target = arena->getPacman()->getLocation();

		return target;
	}

} /* namespace Game */
