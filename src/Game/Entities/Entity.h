/*
 * Entity.h
 *
 *  Created on: Mar 1, 2018
 *      Author: Astrid
 */

#ifndef ENTITY_H_
#define ENTITY_H_
#include <string>
#include "../Util/Util.h"
#include "EntityTypes.h"
using namespace std;

namespace Game
{
	class Entity
	{
	private:

	protected:
		Location location;
		char objectType;
		bool passable;
	public:
		Entity();
		Entity(const Entity& e);
		Entity(const Location& location);

		virtual ~Entity();
		Entity& operator= (const Entity& e);

		virtual void visualize()=0;

		char getObjectType();
		void setObjectType(char type);

		void setX(int x);
		void setY(int y);

		int getX();
		int getY();

		virtual bool isPassable();
	};
}

#endif /* ENTITY_H_ */
