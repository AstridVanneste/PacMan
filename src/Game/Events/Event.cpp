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

Event::Event(const EventType& type, const string& subtype)
{
	this->type = type;
	this->subtype = subtype;
}

Event::~Event()
{
}

Event& Event::operator =(const Event& e)
{
	if(this != &e)
	{
		this->type = e.type;
		this->subtype = e.subtype;
	}

	return *this;
}

const EventType Event::getType() noexcept
{
	return this->type;
}

void Event::setType(const EventType& type) noexcept
{
	this->type = type;
}

const string Event::getSubtype() noexcept
{
	return this->subtype;
}

void Event::setSubtype(const string& subtype) noexcept
{
	this->subtype = subtype;
}

} /* namespace Game */
