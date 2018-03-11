/*
 * Map.cpp
 *
 *  Created on: 4 mrt. 2018
 *      Author: Astrid
 */

#include <fstream>
#include <iostream>
#include <memory>
#include "Map.h"
#include "Gamemanager.h"
#include "Entities/Ghost.h"
using namespace std;

namespace Game
{
	Map::Map()
	{

	}

	Map::~Map()
	{
	}

	void Map::setEntity(Location location, shared_ptr<Entity> entity) noexcept
	{
		map.at(location.x).at(location.y) = entity;
	}

	const shared_ptr<Entity> Map::getEntity(Location location) noexcept
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
				//cout << "read line: " << line << endl;
				for(i.y=0; i.y<line.size(); i.y++)
				{
					shared_ptr<Ghost> ghost;
					shared_ptr<Pacman> pacman;
					switch (line[i.y])
					{
						case '1':
							this->map[i.x].emplace_back(factory->createWall(i,UNDEFINED_WALL));
							break;
						case '0':
							this->map[i.x].emplace_back(factory->createWall(i,EMPTY_WALL));
							break;
						case 'I':
							//INKY
							ghost = make_shared<Ghost>(factory->createGhost(i, INKY));
							this->map[i.x].emplace_back(ghost);
							this->movingEntities.emplace_back(ghost);
							break;
						case 'B':
							//BLINKY
							ghost = make_shared<Ghost>(factory->createGhost(i, BLINKY));
							this->map[i.x].emplace_back(ghost);
							this->movingEntities.emplace_back(ghost);
							break;
						case 'P':
							//PINKY
							ghost = make_shared<Ghost>(factory->createGhost(i, PINKY));
							this->map[i.x].emplace_back(ghost);
							this->movingEntities.emplace_back(ghost);
							break;
						case 'C':
							//CLYDE
							ghost = make_shared<Ghost>(factory->createGhost(i, CLYDE));
							this->map[i.x].emplace_back(ghost);
							this->movingEntities.emplace_back(ghost);
							break;
						case '*':
							//BERRY
							break;
						case 'U':
							//PACMAN
							pacman = make_shared<Pacman>(factory->createPacman(i));
							this->map[i.x].emplace_back(pacman);
							this->movingEntities.emplace_back(ghost);
							break;
						default:
							cout << "unknown input in map file" << endl;
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


		this->setWallTypes();
		return true;
	}

	void Map::setWallTypes()
	{
		//cout << "start setting wall types" << endl;
		cout << "Map size x = " << this->map.size() << " y = " << this->map[0].size() << endl;

		Location i;
		for ( i.x = 0; i.x < this->map.size(); i.x++)
		{
			for (i.y = 0; i.y < this->map[i.x].size(); i.y++)
			{
				//cout << "checking for wall at x = " << i.x << " and y = " << i.y << endl;

				if(!this->map[i.x][i.y]->isPassable())
				{
					char type = 0;


					if(i.x !=0 && !this->map[i.x-1][i.y]->isPassable())							//check if there is a wall above this one.
					{
						//cout << "wall UP" << endl;
						type |= WALL_UP;
					}

					if(i.x < this->map.size()-1 && !this->map[i.x+1][i.y]->isPassable())		//check if there is a wall below this one.
					{
						//cout << "wall DOWN" << endl;
						type |= WALL_DOWN;
					}

					if(i.y != 0 && !this->map[i.x][i.y-1]->isPassable())						//check if there is a wall on the left.
					{
						//cout << "wall LEFT" << endl;
						type |= WALL_LEFT;
					}

					if(i.y < this->map[i.x].size()-1 && !this->map[i.x][i.y+1]->isPassable())	//check if there is a wall on the right.
					{
						//cout << "wall RIGHT" << endl;
						type |= WALL_RIGHT;
					}

					//cout << "wall type set to " << +type << endl;
					this->map[i.x][i.y] = Gamemanager::getInstance().getFactory()->createWall(i, type);

				}
			}
		}
	}

	const unsigned int Map::getSizeX() noexcept
	{
		return this->map.size();
	}

	const unsigned int Map::getSizeY() noexcept
	{
		return this->map[0].size();
	}

	const Location Map::getSize() noexcept
	{
		Location loc;
		loc.x = this->getSizeX();
		loc.y = this->getSizeY();
		return loc;
	}

	const shared_ptr<MovingEntity> Map::getMovingEntity(int i) noexcept
	{
		return this->movingEntities[i];
	}

	const int Map::numberMovingEntities() noexcept
	{
		return this->movingEntities.size();
	}

} /* namespace Game */
