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
	public:
		Pacman();
		Pacman(const Pacman& pacman);
		Pacman(const Location& location);
		virtual ~Pacman();
	};

} /* namespace Game */

#endif /* GAME_ENTITIES_PACMAN_H_ */
