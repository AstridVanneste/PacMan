/*
 * Pacman.cpp
 *
 *  Created on: 10 mrt. 2018
 *      Author: Astrid
 */

#include "Pacman.h"

namespace Game {

Pacman::Pacman()
:MovingEntity()
{
	this->objectType = PACMAN;
}

Pacman::Pacman(const Pacman& pacman)
:MovingEntity(pacman)
{
	this->objectType = PACMAN;
}

Pacman::Pacman(const Location& location)
:MovingEntity(location)
{
	this->objectType = PACMAN;
}

Pacman::~Pacman()
{
}

} /* namespace Game */
