/*
 * Ghost.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef GHOST_H_
#define GHOST_H_
#include <string>
#include "Entity.h"

namespace Game
{
	enum GhostType{Inky, Blinky, Pinky, Clyde};

	class Ghost: Entity
	{
	private:
		GhostType type;
		bool fear;
	public:
		Ghost();
		Ghost(GhostType type);
		Ghost(Location location, GhostType type);
		virtual ~Ghost();

		GhostType getType();
		void setType(GhostType type);

		bool isFear();
		void setFear(bool fear);

		virtual void visualize()=0;
	};
}

#endif /* GHOST_H_ */
