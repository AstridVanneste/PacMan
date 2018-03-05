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
	public:
		Entity();
		Entity(const Location& location);
		virtual ~Entity();

		virtual void visualize()=0;

		char getObjectType();
		void setObjectType(char type);

		void setX(int x);
		void setY(int y);

		int getX();
		int getY();
	};
}

#endif /* ENTITY_H_ */
