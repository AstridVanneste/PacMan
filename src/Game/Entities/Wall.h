/*
 * Wall.h
 *
 *  Created on: 4 mrt. 2018
 *      Author: Astrid
 */

#ifndef GAME_ENTITIES_WALL_H_
#define GAME_ENTITIES_WALL_H_
#include "Entity.h"
#include "WallConstants.h"

namespace Game {

	class Wall : public Entity
	{
	protected:
		char type;		//type is set using the constants in "WallConstants.h"

	public:
		Wall();
		Wall(const Location& location);
		Wall(char type);
		Wall(const Location& location, char type);
		virtual ~Wall();

		void setType(char type) noexcept;
		const char getType() noexcept;

	};

} /* namespace Game */

#endif /* GAME_ENTITIES_WALL_H_ */
