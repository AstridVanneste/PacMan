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
	this->moving = true;
	this->direction = Util::UP;
	this->nextDirection = this->direction;
	this->speed = DEFAULT_SPEED;
	this->offset = this->speed/2;
}

MovingEntity::MovingEntity(const MovingEntity& me)
:Entity(me)
{
	this->moving = me.moving;
	this->direction = me.direction;
	this->nextDirection = me.nextDirection;
	this->speed = me.speed;
	this->offset = me.offset;
}

MovingEntity::MovingEntity(Util::Location location)
:Entity(location)
{
	this->moving = true;
	this->direction = Util::UP;
	this->nextDirection = this->direction;
	this->speed = DEFAULT_SPEED;
	this->offset = this->speed/2;
}

MovingEntity::~MovingEntity()
{
}

MovingEntity& MovingEntity::operator=(const MovingEntity& me)
{
	if(this != &me)
	{
		Entity::operator=(me);
		this->moving = me.moving;
		this->direction = me.direction;
		this->nextDirection = me.nextDirection;
		this->speed = me.speed;
		this->offset = me.offset;
	}
	return *this;
}

bool MovingEntity::update() noexcept
{

	this->offset++;

	if(this->nextDirection == this->direction || this->nextDirection == inverseDirection(this->direction))
	{
		if(this->offset > this->speed)
		{
			//entity has to be moved 1 place
			//this->move();
			//cout << "STRAIGTH or OPPOSITE MOVEMENT" << endl;
			this->offset = 0;
			this->updateDirection();
			return true;
		}
	}
	else
	{
		if(this->offset > this->speed/2)
		{
			//cout << "TURNING" << endl;
			this->offset = 0;
			this->updateDirection();
			return true;
		}
	}
	return false;


}

void MovingEntity::updateDirection() noexcept
{
	this->setDirection(this->nextDirection);
}

const Util::Direction MovingEntity::getDirection() noexcept
{
	return this->direction;
}

void MovingEntity::setDirection(const Util::Direction& direction) noexcept
{
	this->moving = true;
	this->direction = direction;
}

const Util::Direction MovingEntity::getNextDirection() noexcept
{
	return this->nextDirection;
}

void MovingEntity::setNextDirection(const Util::Direction& direction) noexcept
{
	this->nextDirection = direction;
}

const Util::Location MovingEntity::getNextLocation(Util::Location limits) noexcept
{
	Util::Location destination = this->location;

	switch(direction)
	{
	case Util::UP:
		if(destination.x != 0)
		{
			destination.x--;

		}
		else
		{
			destination.x = limits.x-1;
		}
		break;
	case Util::DOWN:
		if(destination.x < limits.x-1)
		{
			destination.x++;
		}
		else
		{
			destination.x = 0;
		}
		break;
	case Util::LEFT:
		if(destination.y != 0)
		{
			destination.y--;
		}
		else
		{
			destination.y = limits.y-1;
		}
		break;
	case Util::RIGHT:
		if(destination.y < limits.y-1)
		{
			destination.y++;
		}
		else
		{
			destination.y = 0;
		}
		break;
	case Util::NONE:
		break;
	}
	return destination;
}

void MovingEntity::setMoving(bool moving) noexcept
{
	this->moving = moving;
}

} /* namespace Game */
