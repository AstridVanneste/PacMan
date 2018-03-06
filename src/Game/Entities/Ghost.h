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

	class Ghost: public Entity
	{
	private:
		GhostType type;
		bool fear;
	public:
		Ghost();
		Ghost(const Ghost& g);
		Ghost(GhostType type);
		Ghost(Location location, GhostType type);
		virtual ~Ghost();


		GhostType getType();
		void setType(GhostType type);

		bool isFear();
		void setFear(bool fear);
	};
}

#endif /* GHOST_H_ */
