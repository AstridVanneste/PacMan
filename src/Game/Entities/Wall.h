/*
 * Wall.h
 *
 *  Created on: 4 mrt. 2018
 *      Author: Astrid
 */

#ifndef GAME_ENTITIES_WALL_H_
#define GAME_ENTITIES_WALL_H_
#include "Entity.h"

namespace Game {
	/*
	 * 		11  = horizontal		1 = vertical
	 *								1
	 *
	 * 		11  = upRight			11 = upLeft
	 * 		1						 1
	 *
	 * 		1   = downRight			 1 = downLeft
	 * 		11						11
	 *
	 * 		1						 1
	 * 		11  = tripleRight		11 = tripleLeft
	 * 		1						 1
	 *
	 * 		1	= tripleUp			111 = tripleDown
	 * 	   111						 1
	 *
	 * 	    1
	 * 	   111  = cross
	 * 	    1
	 */
	enum WallType{horizontal, vertical, upLeft, upRight, downLeft, downRight, tripleUp, tripleDown, tripleLeft, tripleRight, cross};

	class Wall : public Entity
	{
	private:

	public:
		Wall();
		virtual ~Wall();
	};

} /* namespace Game */

#endif /* GAME_ENTITIES_WALL_H_ */
