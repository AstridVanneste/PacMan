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
		this->respawnPoint.x = 0;
		this->respawnPoint.y = 0;
	}

	Pacman::Pacman(const Pacman& pacman)
	:MovingEntity(pacman)
	{
		this->objectType = PACMAN;
		this->respawnPoint = pacman.respawnPoint;
	}

	Pacman::Pacman(const Util::Location& location, const Util::Location& respawnPoint)
	:MovingEntity(location)
	{
		this->objectType = PACMAN;
		if(Settings::Config::getInstance().keyExists(Settings::PACMAN_SPEED))
		{
			this->speed = Settings::Config::getInstance().getValueOfKey<int>(Settings::PACMAN_SPEED);
		}
		this->respawnPoint = respawnPoint;
	}

	Pacman::~Pacman()
	{
	}

	Pacman& Pacman::operator=(const Pacman& p)
	{
		if(this != &p)
		{
			MovingEntity::operator =(p);
			this->respawnPoint = p.respawnPoint;
		}

		return *this;
	}

	void Pacman::respawn() noexcept
	{
		this->location = this->respawnPoint;
	}

} /* namespace Game */
