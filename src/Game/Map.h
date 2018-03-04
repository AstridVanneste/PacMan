/*
 * Map.h
 *
 *  Created on: 4 mrt. 2018
 *      Author: Astrid
 */

#ifndef GAME_MAP_H_
#define GAME_MAP_H_
#include "Entities/Entity.h"
#include <string>
using namespace std;

namespace Game
{

	class Map
	{
	private:
		Entity* map [10][10];
	public:
		Map();
		virtual ~Map();

		void setEntity(Location location, Entity* entity);
		Entity* getEntity(Location location);
		//virtual void visualize()=0;
		bool loadFromFile(string path);
	};

} /* namespace Game */

#endif /* GAME_MAP_H_ */
