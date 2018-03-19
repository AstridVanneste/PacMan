/*
 * MovingEntity.cpp
 *
 *  Created on: 11 mrt. 2018
 *      Author: Astrid
 */

#include "MovingEntity.h"
#include <iostream>
#include "../../Util/Random.h"
using namespace std;

namespace Game
{

MovingEntity::MovingEntity()
:Entity()
{
	this->direction = UP;
	this->speed = DEFAULT_SPEED; 		//1 move/s
	this->offset = 0;
}

MovingEntity::MovingEntity(const MovingEntity& me)
:Entity(me)
{
	this->direction = me.direction;
	this->speed = me.speed;
	this->offset = me.offset;
}

MovingEntity::MovingEntity(Util::Location location)
:Entity(location)
{
	this->direction = UP;
	this->speed = DEFAULT_SPEED; 		//1 move/s
	this->offset = 0;
}

MovingEntity::~MovingEntity()
{
}

MovingEntity& MovingEntity::operator=(const MovingEntity& me)
{
	if(this != &me)
	{
		Entity::operator=(me);
		this->direction = me.direction;
		this->speed = me.speed;
		this->offset = me.offset;
	}
	return *this;
}

bool MovingEntity::update() noexcept
{
	this->offset++;

	if(this->offset > this->speed)
	{
		//entity has to be moved 1 place
		//this->move();

		this->offset = 0;
		return true;
	}
	return false;
}

const Direction MovingEntity::getDirection() noexcept
{
	return this->direction;
}

void MovingEntity::setDirection(const Direction& direction) noexcept
{
	this->direction = direction;
}

void MovingEntity::toggleDirection() noexcept
{
	/*Direction newDirection;
	if(this->direction == NONE)
	{
		newDirection = Direction(Random::getInstance().generateRandom(3));
	}
	else
	{
		newDirection = NONE;
	}
	this->direction = newDirection;
	// cout << "Direction changed to " << this->direction << endl;*/
}

const Util::Location MovingEntity::getNextLocation(Util::Location limits) noexcept
{
	Util::Location destination = this->location;

	switch(direction)
	{
	case UP:
		if(destination.x != 0)
		{
			destination.x--;

		}
		else
		{
			this->toggleDirection();
		}
		break;
	case DOWN:
		if(destination.x < limits.x-1)
		{
			destination.x++;
		}
		else
		{
			this->toggleDirection();
		}
		break;
	case LEFT:
		if(destination.y != 0)
		{
			destination.y--;
		}
		else
		{
			this->toggleDirection();
		}
		break;
	case RIGHT:
		if(destination.y < limits.y-1)
		{
			destination.y++;
		}
		else
		{
			this->toggleDirection();
		}
		break;
	case NONE:
		this->toggleDirection();
		break;
	}
	return destination;
}

} /* namespace Game */
