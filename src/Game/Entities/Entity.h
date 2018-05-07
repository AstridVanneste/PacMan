/*
 * Entity.h
 *
 *  Created on: Mar 1, 2018
 *      Author: Astrid
 */

#ifndef ENTITY_H_
#define ENTITY_H_
#include <string>

#include "../../Util/Direction.h"
#include "../../Util/Location.h"
using namespace std;

namespace Game
{
	class Entity
	{
	private:

	protected:
		Util::Location location;
		bool passable;
	public:
		Entity();
		Entity(const Entity& e);
		Entity(const Util::Location& location);

		virtual ~Entity();
		Entity& operator= (const Entity& e);

		const virtual void visualize()=0;

		const Util::Location getLocation() noexcept;
		void setLocation(const Util::Location& location) noexcept;

		void setX(int x) noexcept;
		void setY(int y) noexcept;

		const int getX() noexcept;
		const int getY() noexcept;

		const virtual bool isPassable() noexcept;
	};
}

#endif /* ENTITY_H_ */
