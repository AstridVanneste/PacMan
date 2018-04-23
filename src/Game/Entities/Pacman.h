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
		Pacman(const Util::Location& location, const Util::Location& respawnPoint);
		virtual ~Pacman();
		Pacman& operator=(const Pacman& p);
	};

} /* namespace Game */

#endif /* GAME_ENTITIES_PACMAN_H_ */
