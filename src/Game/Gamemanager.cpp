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
		this->map = make_shared<Map>();
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
		this->map->loadFromFile("res/Maps/arena2.txt");
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
		for(int i = 0; i < this->map->numberMovingEntities(); i++)
		{
			if(this->map->getMovingEntity(i)->update())
			{
				//move entity on map
				Location destination = this->map->getMovingEntity(i)->getNextLocation(this->map->getSize());

				if(this->map->getEntity(destination)->isPassable())
				{
					Location loc = this->map->getMovingEntity(i)->getLocation();
					this->map->setEntity(this->map->getMovingEntity(i)->getLocation(), factory->createWall(loc, EMPTY_WALL));
					this->map->setEntity(destination, this->map->getMovingEntity(i));
					this->map->getMovingEntity(i)->setLocation(destination);
				}
				else
				{
					this->map->getMovingEntity(i)->toggleDirection();
				}
			}
		}
	}
}

