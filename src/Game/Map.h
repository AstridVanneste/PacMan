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
	const int MAP_LIMIT_HEIGHT = 9;
	const int MAP_LIMIT_WIDTH = 9;

	class Map
	{
	private:
		Entity* map [10][10];
		void setWallTypes();
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
