/*
 * Dot.cpp
 *
 *  Created on: Mar 19, 2018
 *      Author: Astrid
 */

#include "Dot.h"

namespace Game
{

Dot::Dot()
:Entity()
{
	this->objectType = DOT;
	this->value = 0;
}

Dot::Dot(const Dot& dot)
:Entity(dot)
{
	this->objectType = DOT;
	this->value = dot.value;
}

Dot::Dot(const Util::Location& location)
:Entity(location)
{
	this->objectType = DOT;
	this->value = 0;
}

Dot::Dot(const Util::Location& location, int value)
:Entity(location)
{
	this->objectType = DOT;
	this->value = value;
}

Dot::~Dot()
{
}

Dot& Dot::operator=(const Dot& d)
{
	if(this != &d)
	{
		Entity::operator =(d);
		this->value = d.value;
	}
	return *this;
}

} /* namespace Game */
