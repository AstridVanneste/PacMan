/*
 * MovingEntity.h
 *
 *  Created on: 11 mrt. 2018
 *      Author: Astrid
 */

#ifndef GAME_ENTITIES_MOVINGENTITY_H_
#define GAME_ENTITIES_MOVINGENTITY_H_

#include "Entity.h"

namespace Game
{

	enum Direction
	{
		UP , DOWN , LEFT , RIGHT
	};

	class MovingEntity : public Entity
	{
	private:
		Direction direction;
		int speed;						// amount of frames it takes to move from one place to the next
		int offset;						// amount of frames that passed since last movement

		void move() noexcept;
	public:
		MovingEntity();
		MovingEntity(const MovingEntity& me);
		MovingEntity(Location location);

		virtual ~MovingEntity();

		bool update() noexcept;			//returns true if moved (depends on speed and offset)

		const Direction getDirection() noexcept;
		void setDirection(Direction direction) noexcept;
	};

} /* namespace Game */

#endif /* GAME_ENTITIES_MOVINGENTITY_H_ */
