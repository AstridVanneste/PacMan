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
#include <vector>
using namespace std;

namespace Game
{

	/*
	 * 	[ axy	a12		a13		a14	]
	 * 	[ a21	a22		a23		a24 ]
	 * 	[ a31	a32		a33		a34 ]
	 * 	[ a41	a42		a43		a44 ]
	 *
	 *	x = height
	 *	y = width
	 */
	class Map
	{
	private:
		vector<vector<Entity*>> map;
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
