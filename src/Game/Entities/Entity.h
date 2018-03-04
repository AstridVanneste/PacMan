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
using namespace std;

namespace Game
{
	class Entity
	{
	private:
		Location location;
	public:
		Entity();
		Entity(Location location);
		virtual ~Entity();

		void setX(int x);
		void setY(int y);

		int getX();
		int getY();
	};
}

#endif /* ENTITY_H_ */
