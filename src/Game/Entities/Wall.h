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
		int value;

	public:
		Wall();
		Wall(const Wall& w);
		Wall(const Util::Location& location);
		Wall(char type);
		Wall(const Util::Location& location, char type);
		Wall(const Util::Location& location, char type, int value);
		virtual ~Wall();

		Wall& operator=(const Wall& w);

		void setType(char type) noexcept;
		char getType() const noexcept;

		void setValue(int value) noexcept;
		int getValue() const noexcept;

	};

} /* namespace Game */

#endif /* GAME_ENTITIES_WALL_H_ */
