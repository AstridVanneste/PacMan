/*
 * Gamemanager.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#include "Entities/Ghost.h"
#include "Gamemanager.h"
#include "Map.h"

namespace Game
{

	Gamemanager::Gamemanager()
	{
		this->factory = 0;
		this->running = false;
	}


	Gamemanager& Gamemanager::getInstance()
	{
		static Gamemanager instance;
		return instance;
	}

	Gamemanager::~Gamemanager()
	{
		delete this->factory;
	}

	void Gamemanager::start()
	{
		this->running = true;
		//initialize game


		Ghost* ghost = this->factory->createGhost();

		ghost->visualize();

		Map* map = new Map();
		map->loadFromFile("res/Maps/lev1.txt");
	}

	void Gamemanager::run()
	{
		while(true) //todo change this to something logical
		{
			//input
			//update positions
			//visualize
			this->factory->getGraphicsHandler().visualizeAll();
		}
	}

	AbstractFactory* Gamemanager::getFactory()
	{
		return this->factory;
	}

	void Gamemanager::setFactory(AbstractFactory* factory)
	{
		this->factory = factory;
	}
}

