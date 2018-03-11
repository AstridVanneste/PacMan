/*
 * Ghost.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef GHOST_H_
#define GHOST_H_
#include <string>
#include "MovingEntity.h"

namespace Game
{
	enum GhostType{INKY, CLYDE, BLINKY, PINKY};

	class Ghost: public MovingEntity
	{
	protected:
		GhostType type;
		bool fear;
	public:
		Ghost();
		Ghost(const Ghost& g);
		Ghost(GhostType type);
		Ghost(Location location, GhostType type);
		virtual ~Ghost();


		const GhostType getType() noexcept;
		void setType(GhostType type) noexcept;

		const bool isFear() noexcept;
		void setFear(bool fear) noexcept;
	};
}

#endif /* GHOST_H_ */
