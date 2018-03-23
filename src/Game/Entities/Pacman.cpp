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
		this->score = 0;
	}

	Pacman::Pacman(const Pacman& pacman)
	:MovingEntity(pacman)
	{
		this->objectType = PACMAN;
		this->score = pacman.score;
	}

	Pacman::Pacman(const Util::Location& location)
	:MovingEntity(location)
	{
		this->objectType = PACMAN;
		this->score = 0;
	}

	Pacman::~Pacman()
	{
	}

	Pacman& Pacman::operator=(const Pacman& p)
	{
		if(this != &p)
		{
			MovingEntity::operator =(p);
			this->score = p.score;
		}

		return *this;
	}

	const int Pacman::getScore() noexcept
	{
		return this->score;
	}

	void Pacman::setScore(int score) noexcept
	{
		this->score = score;
	}

	void Pacman::addPoints(int points) noexcept
	{
		this->score += points;
		cout << "SCORE: " << this->score << endl;
	}

} /* namespace Game */
