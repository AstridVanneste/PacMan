/*
 * Map.cpp
 *
 *  Created on: 4 mrt. 2018
 *      Author: Astrid
 */

#include "Arena.h"

#include <fstream>
#include <iostream>
#include <memory>
#include "Gamemanager.h"
#include "Entities/Ghost.h"
using namespace std;

namespace Game
{
	Arena::Arena()
	{

	}

	Arena::~Arena()
	{
	}

	void Arena::setEntity(Location location, shared_ptr<Entity> entity) noexcept
	{
		arena.at(location.x).at(location.y) = entity;
	}

	const shared_ptr<Entity> Arena::getEntity(Location location) noexcept
	{
		return this->arena[location.x][location.y];
	}

	bool Arena::loadFromFile(string path)
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
				this->arena.resize(i.x+1);
				//cout << "read line: " << line << endl;
				for(i.y=0; i.y<line.size(); i.y++)
				{
					shared_ptr<Ghost> ghost;
					shared_ptr<Pacman> pacman;
					switch (line[i.y])
					{
						case '1':
							this->arena[i.x].emplace_back(factory->createWall(i,UNDEFINED_WALL));
							break;
						case '0':
							this->arena[i.x].emplace_back(factory->createWall(i,EMPTY_WALL));
							break;
						case 'I':
							//INKY
							ghost = factory->createGhost(i, INKY);
							this->arena[i.x].emplace_back(factory->createWall(i,EMPTY_WALL));
							//this->map[i.x].emplace_back(ghost);
							this->movingEntities.emplace_back(ghost);
							break;
						case 'B':
							//BLINKY
							ghost = factory->createGhost(i, BLINKY);
							this->arena[i.x].emplace_back(factory->createWall(i,EMPTY_WALL));
							//this->map[i.x].emplace_back(ghost);
							this->movingEntities.emplace_back(ghost);
							break;
						case 'P':
							//PINKY
							ghost = factory->createGhost(i, PINKY);
							this->arena[i.x].emplace_back(factory->createWall(i,EMPTY_WALL));
							//this->map[i.x].emplace_back(ghost);
							this->movingEntities.emplace_back(ghost);
							break;
						case 'C':
							//CLYDE
							ghost = factory->createGhost(i, CLYDE);
							this->arena[i.x].emplace_back(factory->createWall(i,EMPTY_WALL));
							//this->map[i.x].emplace_back(ghost);
							this->movingEntities.emplace_back(ghost);
							break;
						case '*':
							//BERRY
							break;
						case 'U':
							//PACMAN
							pacman = factory->createPacman(i);
							this->arena[i.x].emplace_back(factory->createWall(i,EMPTY_WALL));
							//this->map[i.x].emplace_back(pacman);
							this->movingEntities.emplace_back(pacman);
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

	void Arena::setWallTypes()
	{
		//cout << "start setting wall types" << endl;
		cout << "Map size x = " << this->arena.size() << " y = " << this->arena[0].size() << endl;

		Location i;
		for ( i.x = 0; i.x < this->arena.size(); i.x++)
		{
			for (i.y = 0; i.y < this->arena[i.x].size(); i.y++)
			{
				//cout << "checking for wall at x = " << i.x << " and y = " << i.y << endl;

				if(!this->arena[i.x][i.y]->isPassable())
				{
					char type = 0;


					if(i.x !=0 && !this->arena[i.x-1][i.y]->isPassable())							//check if there is a wall above this one.
					{
						//cout << "wall UP" << endl;
						type |= WALL_UP;
					}

					if(i.x < this->arena.size()-1 && !this->arena[i.x+1][i.y]->isPassable())		//check if there is a wall below this one.
					{
						//cout << "wall DOWN" << endl;
						type |= WALL_DOWN;
					}

					if(i.y != 0 && !this->arena[i.x][i.y-1]->isPassable())						//check if there is a wall on the left.
					{
						//cout << "wall LEFT" << endl;
						type |= WALL_LEFT;
					}

					if(i.y < this->arena[i.x].size()-1 && !this->arena[i.x][i.y+1]->isPassable())	//check if there is a wall on the right.
					{
						//cout << "wall RIGHT" << endl;
						type |= WALL_RIGHT;
					}

					//cout << "wall type set to " << +type << endl;
					this->arena[i.x][i.y] = Gamemanager::getInstance().getFactory()->createWall(i, type);

				}
			}
		}
	}

	const unsigned int Arena::getSizeX() noexcept
	{
		return this->arena.size();
	}

	const unsigned int Arena::getSizeY() noexcept
	{
		return this->arena[0].size();
	}

	const Location Arena::getSize() noexcept
	{
		Location loc;
		loc.x = this->getSizeX();
		loc.y = this->getSizeY();
		return loc;
	}

	const shared_ptr<MovingEntity> Arena::getMovingEntity(int i) noexcept
	{
		return this->movingEntities[i];
	}

	const int Arena::numberMovingEntities() noexcept
	{
		return this->movingEntities.size();
	}

	void Arena::moveEntity(int i, Location destination) noexcept
	{
		//Location loc = this->movingEntities[i]->getLocation();

		//move entity on map
		//this->map[destination.x][destination.y] = this->movingEntities[i];
		//set empty entity on src location
		//this->map[loc.x][loc.y] = Gamemanager::getInstance().getFactory()->createWall(loc,EMPTY_WALL);
		//update location in entity
		this->movingEntities[i]->setLocation(destination);

	}

} /* namespace Game */
