/*
 * Map.cpp
 *
 *  Created on: 4 mrt. 2018
 *      Author: Astrid
 */

#include <fstream>
#include <iostream>
#include "Map.h"
using namespace std;

namespace Game
{

	Map::Map()
	{

	}

	Map::~Map()
	{
		delete this->map;
	}

	void Map::setEntity(Location location, Entity* entity)
	{
		this->map[location.x][location.y] = entity;
	}

	Entity* Map::getEntity(Location location)
	{
		return this->map[location.x][location.y];
	}

	bool Map::loadFromFile(string path)
	{
		ifstream file;
		file.open(path);
		if(file.is_open())
		{
			Location i;
			i.x = 0;
			i.y = 0;
			while(!file.eof())
			{
				char output;
				file >> output;
				if(output == 1)
				{
					this->setEntity(i, new Entity(i));
					if(i.x > 10)
					{
						i.x = 0;
						i.y++;
					}
					else
					{
						i.x++;
					}

				}
			}
			file.close();
		}
		else
		{
			cout << "unable to open file";
		}
		return true;
	}

} /* namespace Game */
