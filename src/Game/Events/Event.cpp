/*
 * Event.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: Astrid
 */

#include "Event.h"

namespace Game
{

Event::Event()
{
	this->type = QUIT;
}

Event::Event(const EventType& type)
{
	this->type = type;
}

Event::~Event()
{
}

const EventType Event::getType() noexcept
{
	return this->type;
}

void Event::setType(const EventType& type) noexcept
{
	this->type = type;
}

} /* namespace Game */
