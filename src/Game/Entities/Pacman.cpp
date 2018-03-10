/*
 * Pacman.cpp
 *
 *  Created on: 10 mrt. 2018
 *      Author: Astrid
 */

#include "Pacman.h"

namespace Game {

Pacman::Pacman()
:Entity()
{
	this->objectType = PACMAN;
}

Pacman::Pacman(const Pacman& pacman)
:Entity(pacman)
{
	this->objectType = PACMAN;
}

Pacman::Pacman(const Location& location)
:Entity(location)
{
	this->objectType = PACMAN;
}

Pacman::~Pacman()
{
}

} /* namespace Game */
