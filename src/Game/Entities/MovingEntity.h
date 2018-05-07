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
	const int DEFAULT_SPEED = 10;

	class MovingEntity : public Entity
	{
	protected:
		Util::Direction direction;
		Util::Direction nextDirection;
		bool moving;
		int speed;						// amount of frames it takes to move from one place to the next
		int offset;						// amount of frames that passed since last movement
		Util::Location respawnPoint;

	public:
		MovingEntity();
		MovingEntity(const MovingEntity& me);
		MovingEntity(Util::Location location);

		virtual ~MovingEntity();

		MovingEntity& operator=(const MovingEntity& me);

		virtual bool update() noexcept;			//returns true if moved (depends on speed and offset)

		void updateDirection() noexcept;

		Util::Direction getDirection() const noexcept;
		void setDirection(const Util::Direction& direction) noexcept;

		Util::Direction getNextDirection() const noexcept;
		void setNextDirection(const Util::Direction& direction) noexcept;

		Util::Location getNextLocation(Util::Location limits) const noexcept;

		void setMoving(bool moving) noexcept;

		virtual void respawn() noexcept;
	};

} /* namespace Game */

#endif /* GAME_ENTITIES_MOVINGENTITY_H_ */
