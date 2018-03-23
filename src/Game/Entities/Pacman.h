/*
 * Pacman.h
 *
 *  Created on: 10 mrt. 2018
 *      Author: Astrid
 */

#ifndef GAME_ENTITIES_PACMAN_H_
#define GAME_ENTITIES_PACMAN_H_

#include "MovingEntity.h"

namespace Game
{

	class Pacman : public MovingEntity
	{
	private:
		int score;
	public:
		Pacman();
		Pacman(const Pacman& pacman);
		Pacman(const Util::Location& location);
		virtual ~Pacman();
		Pacman& operator=(const Pacman& p);

		const int getScore() noexcept;
		void setScore(int score) noexcept;
		void addPoints(int points) noexcept;
	};

} /* namespace Game */

#endif /* GAME_ENTITIES_PACMAN_H_ */
