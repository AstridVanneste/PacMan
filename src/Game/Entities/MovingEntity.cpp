/*
 * MovingEntity.cpp
 *
 *  Created on: 11 mrt. 2018
 *      Author: Astrid
 */

#include "MovingEntity.h"
#include <iostream>
using namespace std;

namespace Game {

MovingEntity::MovingEntity()
:Entity()
{
	this->direction = UP;
	this->speed = 60; 		//1 move/s
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
	this->speed = 60; 		//1 move/s
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
		this->move();

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
		break;
	case DOWN:
		break;
	case LEFT:
		break;
	case RIGHT:
		break;
	default:
		cout << "Invalid direction" << endl;
	}
}

} /* namespace Game */
