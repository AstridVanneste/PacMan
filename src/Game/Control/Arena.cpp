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
#include "../Entities/Ghost.h"
#include "../../Settings/Config.h"
using namespace std;

namespace Game
{
	Arena::Arena()
	{
	}

	Arena::Arena(const Arena& a)
	{
		this->pacman = a.pacman;
		this->ghosts = a.ghosts;
		this->arena = a.arena;
	}

	Arena& Arena::operator=(const Arena& a)
	{
		if(this != &a)
		{
			this->pacman = a.pacman;
			this->ghosts = a.ghosts;
			this->arena = a.arena;
		}
		return *this;
	}

	Arena::~Arena()
	{
	}

	void Arena::setWall(const Util::Location& location, shared_ptr<Wall> wall) noexcept
	{
		arena[location.x][location.y] = wall;
	}

	const shared_ptr<Wall> Arena::getWall(const Util::Location& location) noexcept
	{
		return this->arena[location.x][location.y];
	}

	bool Arena::loadFromFile(string path)
	{
		//cout << "started loading from file" << endl;

		shared_ptr<AbstractFactory> factory = Gamemanager::getInstance().getFactory();
		ifstream file;
		file.open(path);

		int numDots = 0;

		if(file.is_open())
		{
			//cout << "file opened" << endl;
			Util::Location i;
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
							this->ghosts.emplace_back(ghost);
							break;
						case 'B':
							//BLINKY
							ghost = factory->createGhost(i, BLINKY);
							this->arena[i.x].emplace_back(factory->createWall(i,EMPTY_WALL));
							//this->map[i.x].emplace_back(ghost);
							this->ghosts.emplace_back(ghost);
							break;
						case 'P':
							//PINKY
							ghost = factory->createGhost(i, PINKY);
							this->arena[i.x].emplace_back(factory->createWall(i,EMPTY_WALL));
							//this->map[i.x].emplace_back(ghost);
							this->ghosts.emplace_back(ghost);
							break;
						case 'C':
							//CLYDE
							ghost = factory->createGhost(i, CLYDE);
							this->arena[i.x].emplace_back(factory->createWall(i,EMPTY_WALL));
							//this->map[i.x].emplace_back(ghost);
							this->ghosts.emplace_back(ghost);
							break;
						case '*':
							//DOT
							this->arena[i.x].emplace_back(factory->createWall(i, DOT_WALL, Settings::Config::getInstance().getValueOfKey<int>(Settings::DOT_VALUE)));
							numDots++;
							break;
						case '#':
							//POWER PELLET
							this->arena[i.x].emplace_back(factory->createWall(i, POWER_PELLET, Settings::Config::getInstance().getValueOfKey<int>(Settings::POWER_PELLET_VALUE)));
							numDots++;
							break;
						case 'U':
							//PACMAN
							pacman = factory->createPacman(i, i);
							this->arena[i.x].emplace_back(factory->createWall(i,EMPTY_WALL));
							//this->map[i.x].emplace_back(pacman);
							this->pacman = pacman;
							break;
						default:
							cout << "unknown input in map file" << endl;
					}
				}

				i.x++;

			}
			file.close();

			Gamemanager::getInstance().getGameInfo()->setDotsLeft(numDots);
			//cout << "file closed" << endl;
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
		//cout << "Map size x = " << this->arena.size() << " y = " << this->arena[0].size() << endl;

		Util::Location i;
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
					this->arena[i.x][i.y]->setType(type);
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

	const Util::Location Arena::getSize() noexcept
	{
		Util::Location loc;
		loc.x = this->getSizeX();
		loc.y = this->getSizeY();
		return loc;
	}

	const shared_ptr<Ghost> Arena::getGhost(int i) noexcept
	{
		return this->ghosts[i];
	}

	const int Arena::numberGhosts() noexcept
	{
		return this->ghosts.size();
	}

	void Arena::moveGhost(int i, Util::Location destination) noexcept
	{
		this->ghosts[i]->setLocation(destination);
	}

	void Arena::movePacman(Util::Location destination) noexcept
	{
		this->pacman->setLocation(destination);
	}

	void Arena::visualize()
	{
		Util::Location i;
		for(i.x = 0; i.x < this->getSizeX(); i.x++)
		{
			for(i.y = 0; i.y < this->getSizeY(); i.y++)
			{
				this->getWall(i)->visualize();
			}
		}

		for(unsigned int j = 0; j < this->ghosts.size(); j++)
		{
			this->ghosts[j]->visualize();
		}

		this->pacman->visualize();
	}

	const shared_ptr<Pacman> Arena::getPacman() noexcept
	{
		return this->pacman;
	}

	const shared_ptr<vector<Util::Direction>> Arena::getPosDir(const Util::Location& loc) noexcept
	{
		shared_ptr<vector<Util::Direction>> directions = make_shared<vector<Util::Direction>>();
		//UP
		Util::Location tmpLoc = loc;
		tmpLoc.x--;
		if(tmpLoc.x >= 0 && this->getWall(tmpLoc)->isPassable())
		{
			directions->push_back(Util::UP);
		}

		//DOWN
		tmpLoc = loc;
		tmpLoc.x++;
		if(tmpLoc.x < this->arena.size() && this->getWall(tmpLoc)->isPassable())
		{
			directions->push_back(Util::DOWN);
		}

		//LEFT
		tmpLoc = loc;
		tmpLoc.y--;
		if(tmpLoc.y >= 0 && this->getWall(tmpLoc)->isPassable())
		{
			directions->push_back(Util::LEFT);
		}

		//RIGHT
		tmpLoc = loc;
		tmpLoc.y++;
		if(tmpLoc.y < arena[0].size() && this->getWall(tmpLoc)->isPassable())
		{
			directions->push_back(Util::RIGHT);
		}

		return directions;
	}

	const bool Arena::detectWallCollision(Util::Location& destination) noexcept
	{
		return !this->arena[destination.x][destination.y]->isPassable();
	}

	const bool Arena::detectGhostCollision() noexcept
	{
		for(unsigned int i = 0; i < this->ghosts.size(); i++)
		{
			if(this->ghosts[i]->getLocation() == this->pacman->getLocation())
			{
				return true;
			}
		}
		return false;
	}

	void Arena::setFleeMode() noexcept
	{
		for(int i = 0; i < this->ghosts.size(); i++)
		{
			this->ghosts[i]->setMode(FLEE);
		}
	}

	void Arena::handleGhostCollision() noexcept
	{
		for(unsigned int i = 0; i < this->ghosts.size(); i++)
		{
			if(this->ghosts[i]->getLocation() == this->pacman->getLocation())
			{
				if(this->ghosts[i]->getMode() != FLEE)
				{
					if(!Settings::Config::getInstance().getValueOfKey<bool>(Settings::GOD_MODE))
					{
						this->pacman->respawn();
						Gamemanager::getInstance().getGameInfo()->decreaseLives();
					}
				}
				else
				{
					this->ghosts[i]->respawn();
					this->ghosts[i]->toggleMode();
					Gamemanager::getInstance().getGameInfo()->addScore(Settings::Config::getInstance().getValueOfKey<int>(Settings::GHOST_VALUE));
				}
			}
		}
	}


} /* namespace Game */
