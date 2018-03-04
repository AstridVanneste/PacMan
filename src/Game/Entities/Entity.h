/*
 * Entity.h
 *
 *  Created on: Mar 1, 2018
 *      Author: Astrid
 */

#ifndef ENTITY_H_
#define ENTITY_H_
#include <string>
using namespace std;

namespace Game
{
	class Entity
	{
	private:
		int x;
		int y;
		string image; //path to the image with the appearance of the entity
	public:
		Entity();
		Entity(int x, int y, string image);
		virtual ~Entity();

		void setX(int x);
		void setY(int y);

		int getX();
		int getY();
	};
}

#endif /* ENTITY_H_ */
