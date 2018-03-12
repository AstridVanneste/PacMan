/*
 * MovingEntity.cpp
 *
 *  Created on: 11 mrt. 2018
 *      Author: Astrid
 */

#include "MovingEntity.h"
#include <iostream>
#include "../Util/Random.h"
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

MovingEntity::MovingEntity(Location location)
:Entity(location)
{
	this->direction = UP;
	this->speed = DEFAULT_SPEED; 		//1 move/s
	this->offset = 0;
}

MovingEntity::~MovingEntity()
{
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

void MovingEntity::move() noexcept
{
	switch (this->direction)
	{
	case UP:
		if(this->location.x != 0)
		{
			this->location.x--;
		}
		break;
	case DOWN:
		this->location.x++;
		break;
	case LEFT:
		if(this->location.y != 0)
		{
			this->location.y--;
		}
		break;
	case RIGHT:
		this->location.y++;
		break;
	default:
		cout << "Invalid direction" << endl;
	}
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
	Direction newDirection;
	do
	{
		newDirection = Direction(Random::getInstance().generateRandom(3));
	}while(newDirection == this->direction);
	this->direction = newDirection;
	//cout << "Direction changed to " << this->direction;
}

const Location MovingEntity::getNextLocation(Location limits) noexcept
{
	Location destination = this->location;

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
		if(destination.x < limits.x)
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
		if(destination.y < limits.y)
		{
			destination.y++;

		}
		else
		{
			this->toggleDirection();
		}
		break;
	}
	return destination;
}

} /* namespace Game */
