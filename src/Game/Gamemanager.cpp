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
		this->graphicsHandler = 0;
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
		delete this->graphicsHandler;
	}

	void Gamemanager::start()
	{
		this->running = true;
		//initialize game
		this->graphicsHandler = this->factory->createGraphicsHandler();


		Ghost* ghost = this->factory->createGhost();

		ghost->visualize();

		Map* map = new Map();
		map->loadFromFile("res/Maps/lev1.txt");
	}

	AbstractFactory* Gamemanager::getFactory()
	{
		return this->factory;
	}

	void Gamemanager::setFactory(AbstractFactory* factory)
	{
		this->factory = factory;
	}

	Graphics_Handler* Gamemanager::getGraphicsHandler()
	{
		return this->graphicsHandler;
	}

	void Gamemanager::setGraphicsHandler(Graphics_Handler* graphicsHandler)
	{
		this->graphicsHandler = graphicsHandler;
	}
}

