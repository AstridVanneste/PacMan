/*
 * Gamemanager.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#include <iostream>
#include "Entities/Ghost.h"
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
		this->map->loadFromFile("res/Maps/lev1.txt");
		cout << "Init graphics" << endl;
		this->factory->getGraphicsHandler().init();
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
			//update positions
			end = this->eventHandler->handleEvents();
			//visualize

			//ghost->visualize();
			this->factory->getGraphicsHandler().visualizeAll(this->map);
			//this->factory->getGraphicsHandler().delay(3000);

			unsigned int endTime = this->factory->getGraphicsHandler().getTime();
			if((endTime - startTime) < (1/FRAMERATE) * 1000)
			{
				this->factory->getGraphicsHandler().delay((1/FRAMERATE) * 1000 - (endTime - startTime));
			}
		}
	}

	shared_ptr<AbstractFactory> Gamemanager::getFactory()
	{
		return this->factory;
	}

	void Gamemanager::setFactory(shared_ptr<AbstractFactory> factory)
	{
		this->factory = factory;
	}
}

