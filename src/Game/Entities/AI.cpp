/*
 * AI.cpp
 *
 *  Created on: 18 mrt. 2018
 *      Author: Astrid
 */

#include "AI.h"
#include <math.h>
#include <iostream>
#include "../Gamemanager.h"
#include "../Arena.h"

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

	AI& AI::operator=(const AI& ai)
	{
		if(this != &ai)
		{
			this->mode = ai.mode;
		}
		return *this;
	}

	AI::~AI()
	{
	}

	const Direction AI::getNewDirection(const Util::Location& loc, Direction direction) noexcept
	{
		Util::Location target;
		switch(mode)
		{
		case SCATTER:
			target = this->getScatterTarget();
			break;
		case CHASE:
			target = this->getChaseTarget();
			break;
		case FRIGHTENED:
			target = this->getFrightenedTarget();
			break;
		}

		return this->getOptimalDirection(loc,target, direction);
	}

	const int AI::getDistance(const Util::Location& target, const Util::Location& loc) noexcept
	{
		int distance = pow((loc.x - target.x),2) + pow((loc.y - target.y),2);

		return distance;
	}

	const Direction AI::getOptimalDirection(const Util::Location& loc, const Util::Location& target, Direction direction) noexcept
	{
		Direction newDirection;
		shared_ptr<vector<Direction>> directions = Gamemanager::getInstance().getArena()->getPosDir(loc);

		if(directions->size() == 1)
		{
			return directions[0];
		}

		for(int i =0; i < directions->size(); i++)
		{
			switch(directions[i])
			{
			case UP:
				break;
			case DOWN:
				break;
			case LEFT:
				break;
			case RIGHT:
				break;
			}
		}

		return newDirection;
	}

	const Util::Location AI::getScatterTarget() noexcept
	{
		Util::Location target = Gamemanager::getInstance().getArena()->getPacman()->getLocation();

		return target;
	}

	const Util::Location AI::getChaseTarget() noexcept
	{
		Util::Location target = Gamemanager::getInstance().getArena()->getPacman()->getLocation();

		return target;
	}

	const Util::Location AI::getFrightenedTarget() noexcept
	{
		Util::Location target = Gamemanager::getInstance().getArena()->getPacman()->getLocation();

		return target;
	}

} /* namespace Game */
