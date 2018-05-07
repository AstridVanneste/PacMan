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
#include "../Control/Gamemanager.h"
#include "../Control/Arena.h"

namespace Game
{

	AI::AI()
	{
		this->modeControl = make_shared<ModeControl>();
		this->scatterTarget.x = 0;
		this->scatterTarget.y = 0;
	}

	AI::AI(const AI& ai)
	{
		this->modeControl = ai.modeControl;
		this->scatterTarget = ai.scatterTarget;
	}

	AI& AI::operator=(const AI& ai)
	{
		if(this != &ai)
		{
			this->modeControl = ai.modeControl;
			this->scatterTarget = ai.scatterTarget;
		}
		return *this;
	}

	AI::~AI()
	{
	}

	AImode AI::getMode() const noexcept
	{
		return this->modeControl->getMode();
	}

	void AI::setMode(const AImode& mode) noexcept
	{
		this->modeControl->setMode(mode);
	}

	void AI::toggleMode() noexcept
	{
		this->modeControl->toggleMode();
	}

	Util::Direction AI::getNewDirection(const Util::Location& loc, Util::Direction direction) const noexcept
	{
		Util::Location target;
		switch(this->modeControl->getMode())
		{
		case SCATTER:
			target = this->scatterTarget;
			break;
		case CHASE:
			target = this->getChaseTarget(loc);
			break;
		case FLEE:
			target = this->getFrightenedTarget();
			break;
		}

		return this->getOptimalDirection(loc,target, direction);
	}

	int AI::getDistance(const Util::Location& p1, const Util::Location& p2) const noexcept
	{
		int distance = pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2);
		return distance;
	}

	Util::Direction AI::getOptimalDirection(const Util::Location& loc, const Util::Location& target, Util::Direction oldDirection) const noexcept
	{
		Util::Direction newDirection;
		shared_ptr<vector<Util::Direction>> directions = Gamemanager::getInstance().getArena()->getPosDir(loc);

		//cout << "===================================================================================" << endl;
		//cout << "headed for TARGET = " << target << endl;
		if(directions->size() == 1)
		{
			//cout << "only 1 possible direction" << endl;
			return directions->at(0);
		}

		//cout << "possible directions = " << directions->size() << endl;
		//cout << "old direction = " << oldDirection << " and inverse = " << inverseDirection(oldDirection) << endl;

		int distance;
		AImode mode = this->modeControl->getMode();
		if(mode != FLEE)
		{
			distance = numeric_limits<int>::max();
		}
		else
		{
			distance = 0;
		}
		for(unsigned int i =0; i < directions->size(); i++)
		{
			Util::Location newLoc = loc + directions->at(i);
			int temp = this->getDistance(newLoc, target);

			//cout << directions->at(i) <<" -> distance = " << temp << endl;

			if((temp < distance && mode != FLEE) || (temp > distance && mode == FLEE))
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

	Util::Location AI::getFrightenedTarget() const noexcept
	{
		Util::Location target = Gamemanager::getInstance().getArena()->getPacman()->getLocation();

		return target;
	}

} /* namespace Game */
