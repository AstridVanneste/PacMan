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
		this->map = new Map();
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
		delete this->map;
	}

	void Gamemanager::start()
	{
		this->running = true;
		//initialize game
		this->map->loadFromFile("res/Maps/lev1.txt");
		cout << "Init graphics" << endl;
		//this->factory->getGraphicsHandler().init();
		cout << "Start run()" << endl;
		//this->run();
	}

	void Gamemanager::run()
	{
		while(true) //todo change this to something logical
		{
			//input
			//update positions
			//visualize
			Ghost* ghost = this->factory->createGhost();
			ghost->visualize();
			this->factory->getGraphicsHandler().visualizeAll();
			//this->factory->getGraphicsHandler().delay(3000);
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

