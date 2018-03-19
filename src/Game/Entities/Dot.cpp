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
	this->value = 0;
}

Dot::Dot(const Dot& dot)
:Entity(dot)
{
	this->value = dot.value;
}

Dot::Dot(const Util::Location& location)
:Entity(location)
{
	this->value = 0;
}

Dot::Dot(const Util::Location& location, int value)
:Entity(location)
{
	this->value = value;
}

Dot::~Dot()
{
}

} /* namespace Game */
