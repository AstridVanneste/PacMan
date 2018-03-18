/*
 * Gamemanager.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#include <iostream>
#include "Entities/Ghost.h"
#include "Entities/Wall.h"
#include "Entities/MovingEntity.h"
#include "Gamemanager.h"
using namespace std;

namespace Game
{

	Gamemanager::Gamemanager()
	{
		this->factory = 0;
		this->map = make_shared<Arena>();
		this->running = false;
	}


	Gamemanager& Gamemanager::getInstance()
	{
		static Gamemanager instance;
		return instance;
	}

	Gamemanager::~Gamemanager()
	{
	}

	void Gamemanager::start()
	{
		this->running = true;
		//initialize game
		this->map->loadFromFile("res/Maps/arena3.txt");
		cout << "Init graphics" << endl;
		this->factory->getGraphicsHandler().init(this->map->getSize());
		this->eventHandler = this->factory->createEventHandler();
		cout << "Start run()" << endl;
		this->run();
	}

	void Gamemanager::run()
	{
		bool end = false;
		shared_ptr<Ghost> ghost = this->factory->createGhost();
		while(!end)
		{
			unsigned int startTime = this->factory->getGraphicsHandler().getTime();

			//input
			end = this->eventHandler->handleEvents();

			//update positions
			this->update();

			//visualize
			this->factory->getGraphicsHandler().visualizeAll(this->map);

			//limit FPS
			unsigned int endTime = this->factory->getGraphicsHandler().getTime();
			unsigned int frameTime = endTime - startTime;
			if(FRAME_DELAY > frameTime)
			{
				this->factory->getGraphicsHandler().delay(FRAME_DELAY - frameTime);
			}
		}
	}

	const shared_ptr<AbstractFactory> Gamemanager::getFactory() noexcept
	{
		return this->factory;
	}

	void Gamemanager::setFactory(shared_ptr<AbstractFactory> factory) noexcept
	{
		this->factory = factory;
	}

	void Gamemanager::update()
	{
		for(int i = 0; i < this->map->numberGhosts(); i++)
		{
			if(this->map->getGhost(i)->update())
			{
				//move entity on map
				Location destination = this->map->getGhost(i)->getNextLocation(this->map->getSize());

				if(this->map->getWall(destination)->isPassable())
				{
					this->map->moveGhost(i, destination);
				}
				else
				{
					this->map->getGhost(i)->toggleDirection();
				}
			}
		}

		if(this->map->getPacman()->update())
		{
			Location destination = this->map->getPacman()->getNextLocation(this->map->getSize());

			if(this->map->getWall(destination)->isPassable())
			{
				this->map->movePacman(destination);
			}
			else
			{
				this->map->getPacman()->toggleDirection();
			}
		}
	}

	const shared_ptr<Pacman> Gamemanager::getPacman() noexcept
	{
		return this->map->getPacman();
	}
}

