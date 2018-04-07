/*
 * Pacman.cpp
 *
 *  Created on: 10 mrt. 2018
 *      Author: Astrid
 */

#include "Pacman.h"
#include "../../Settings/Config.h"

namespace Game {

	Pacman::Pacman()
	:MovingEntity()
	{
		this->objectType = PACMAN;
		if(Settings::Config::getInstance().keyExists(Settings::PACMAN_SPEED))
		{
			this->speed = Settings::Config::getInstance().getValueOfKey<int>(Settings::PACMAN_SPEED);
		}
	}

	Pacman::Pacman(const Pacman& pacman)
	:MovingEntity(pacman)
	{
		this->objectType = PACMAN;
	}

	Pacman::Pacman(const Util::Location& location)
	:MovingEntity(location)
	{
		this->objectType = PACMAN;
		if(Settings::Config::getInstance().keyExists(Settings::PACMAN_SPEED))
		{
			this->speed = Settings::Config::getInstance().getValueOfKey<int>(Settings::PACMAN_SPEED);
		}
	}

	Pacman::~Pacman()
	{
	}

	Pacman& Pacman::operator=(const Pacman& p)
	{
		if(this != &p)
		{
			MovingEntity::operator =(p);
		}

		return *this;
	}

} /* namespace Game */
