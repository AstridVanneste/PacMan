/*
 * Map.cpp
 *
 *  Created on: 4 mrt. 2018
 *      Author: Astrid
 */

#include "Map.h"

namespace Game
{

	Map::Map()
	{

	}

	Map::~Map()
	{

	}

	void Map::setEntity(Location location, Entity* entity)
	{
		this->map[location.x][location.y] = entity;
	}

	Entity* Map::getEntity(Location location)
	{
		return this->map[location.x][location.y];
	}

} /* namespace Game */
