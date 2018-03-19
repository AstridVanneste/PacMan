/*
 * AI.cpp
 *
 *  Created on: 18 mrt. 2018
 *      Author: Astrid
 */

#include "AI.h"
#include <math.h>
#include <iostream>
#include <limits>
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

	const Direction AI::getOptimalDirection(const Util::Location& loc, const Util::Location& target, Direction oldDirection) noexcept
	{
		Direction newDirection;
		shared_ptr<vector<Direction>> directions = Gamemanager::getInstance().getArena()->getPosDir(loc);

		cout << "===================================================================================" << endl;
		if(directions->size() == 1)
		{
			cout << "only 1 possible direction" << endl;
			return directions->at(0);
		}

		cout << "possible directions = " << directions->size() << endl;
		cout << "old direction = " << oldDirection << " and inverse = " << inverseDirection(oldDirection) << endl;

		int distance = numeric_limits<int>::max();
		for(unsigned int i =0; i < directions->size(); i++)
		{
			Util::Location newLoc = loc + directions->at(i);
			int temp = this->getDistance(newLoc, target);

			cout << directions->at(i) <<" -> distance = " << temp << endl;

			if(temp < distance)
			{
				if(directions->at(i) != inverseDirection(oldDirection))
				{
					distance = temp;
					newDirection = directions->at(i);
				}
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
