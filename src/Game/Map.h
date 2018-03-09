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
#include <memory>
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
		vector<vector<shared_ptr<Entity>>> map;
		void setWallTypes();
	public:
		Map();
		virtual ~Map();

		void setEntity(Location location, shared_ptr<Entity> entity);
		shared_ptr<Entity> getEntity(Location location);
		bool loadFromFile(string path);
		unsigned int getSizeX();
		unsigned int getSizeY();
	};

} /* namespace Game */

#endif /* GAME_MAP_H_ */
