/*
 * Map.cpp
 *
 *  Created on: 4 mrt. 2018
 *      Author: Astrid
 */

#include <fstream>
#include <iostream>
#include "Map.h"
#include "Gamemanager.h"
using namespace std;

namespace Game
{

	Map::Map()
	{

	}

	Map::~Map()
	{
		//delete this->map;
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
		AbstractFactory* factory = Gamemanager::getInstance().getFactory();
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
					this->setEntity(i, factory->createWall());
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

	void Map::setWallTypes()
	{
		Location i;
		for ( i.x = 0; i.x < MAP_LIMIT_HEIGHT; i.x++)
		{
			for (i.y = 0; i.y < MAP_LIMIT_WIDTH; i.y++)
			{

				if(this->map[i.x][i.y]->getObjectType() == WALL)
				{
					char type = 0;

					if(i.y !=0 && this->map[i.x][i.y - 1]->getObjectType() == WALL)						//check if there is a wall above this one.
					{
						type |= UP;
					}
					if(i.y != MAP_LIMIT_HEIGHT && this->map[i.x][i.y + 1]->getObjectType() == WALL)		//check if there is a wall below this one.
					{
						type |= DOWN;
					}
					if(i.x != 0 && this->map[i.x - 1][i.y]->getObjectType() == WALL)					//check if there is a wall on the left.
					{
						type |= LEFT;
					}
					if(i.x != MAP_LIMIT_WIDTH && this->map[i.x + 1][i.y]->getObjectType() == WALL)		//check if there is a wall on the right.
					{
						type |= RIGHT;
					}

					this->map[i.x][i.y]->setObjectType(type);
				}
			}
		}
	}

} /* namespace Game */
