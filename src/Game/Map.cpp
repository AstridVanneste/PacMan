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
		Location i;

		cout<<"destructor of map called" << endl;

		for(i.x=0;i.x<this->map.size();i.x++)
		{
			for(i.y=0;i.y<this->map[i.x].size();i.y++)
			{
				delete this->map[i.x][i.y];
			}
		}
	}

	void Map::setEntity(Location location, Entity* entity)
	{
		map.at(location.x).at(location.y) = entity;
	}

	Entity* Map::getEntity(Location location)
	{
		return this->map[location.x][location.y];
	}

	bool Map::loadFromFile(string path)
	{
		cout << "started loading from file" << endl;

		shared_ptr<AbstractFactory> factory = Gamemanager::getInstance().getFactory();
		ifstream file;
		file.open(path);

		if(file.is_open())
		{
			cout << "file opened" << endl;
			Location i;
			i.x = 0;
			i.y = 0;


			while(!file.eof())
			{
				string line;
				getline(file, line, '\n');
				this->map.resize(i.x+1);
				cout << "read line: " << line << endl;
				for(i.y=0; i.y<line.size(); i.y++)
				{
					//cout << "Input of " << line[i.y] << " at x = " << i.x << " and y = " << i.y << endl;
					if(line[i.y] == '1')
					{
						this->map[i.x].emplace_back(factory->createWall(i));
						cout << "Wall set at x = " << i.x << " and y = " << i.y << endl;
					}
					else if(line[i.y] == '0')
					{
						this->map[i.x].emplace_back(factory->createWall(i,EMPTY_WALL));
					}
				}

				i.x++;

			}
			file.close();
			cout << "file closed" << endl;
		}
		else
		{
			cout << "unable to open file";
			return false;
		}


		//this->setWallTypes();
		return true;
	}

	void Map::setWallTypes()
	{
		cout << "start setting wall types" << endl;

		Location i;
		for ( i.x = 0; i.x < this->map.size(); i.x++)
		{
			for (i.y = 0; i.y < this->map[i.x].size(); i.y++)
			{
				cout << "checking for wall at x = " << i.x << " and y = " << i.y << endl;

				if(this->map[i.x][i.y]->getObjectType() == WALL)
				{
					char type = 0;

					cout << "checking wall above" << endl;
					if(i.x !=0 && this->map[i.x-1][i.y]->getObjectType() == WALL)						//check if there is a wall above this one.
					{
						type |= UP;
					}
					cout << "checking wall below" << endl;
					if(i.x >= this->map.size() && this->map[i.x + 1][i.y]->getObjectType() == WALL)		//check if there is a wall below this one.
					{
						type |= DOWN;
					}
					cout << "checking wall left" << endl;
					if(i.y != 0 && this->map[i.x][i.y - 1]->getObjectType() == WALL)					//check if there is a wall on the left.
					{
						type |= LEFT;
					}
					cout << "checking wall right" << endl;
					if(i.y >= this->map[i.x].size() && this->map[i.x][i.y + 1]->getObjectType() == WALL)		//check if there is a wall on the right.
					{
						type |= RIGHT;
					}

					cout << "wall type set to " << +type << endl;
					this->map[i.x][i.y] = Gamemanager::getInstance().getFactory()->createWall(i, type);

				}
			}
		}
	}

} /* namespace Game */