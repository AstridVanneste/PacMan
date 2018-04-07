/*
 * Gamemanager.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#include <iostream>
#include "../Entities/Ghost.h"
#include "../Entities/Wall.h"
#include "../Entities/MovingEntity.h"
#include "../../Settings/Config.h"
#include "Gamemanager.h"
using namespace std;

namespace Game
{

	Gamemanager::Gamemanager()
	{
		this->factory = nullptr;
		this->gameInfo = nullptr;
		this->arena = make_shared<Arena>();
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

		// load settings
		Settings::Config::getInstance().setPath("res/Settings.txt");

		//initialize game info
		//TODO change arguments to values provided in settings
		this->gameInfo = this->factory->createGameInfo(0,3,RUNNING);

		//initialize game arena
		this->arena->loadFromFile("res/Maps/arena3.txt");
		cout << "Init graphics" << endl;
		this->factory->getGraphicsHandler().init(this->arena->getSize());

		// create event handler
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
			this->factory->getGraphicsHandler().visualizeAll(this->arena);
			this->gameInfo->visualize();

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
		for(int i = 0; i < this->arena->numberGhosts(); i++)
		{
			if(this->arena->getGhost(i)->update())
			{
				//move entity on map
				Util::Location destination = this->arena->getGhost(i)->getNextLocation(this->arena->getSize());

				if(!this->arena->detectWallCollision(destination))
				{
					this->arena->moveGhost(i, destination);
				}
			}
		}

		if(this->arena->getPacman()->update())
		{
			Util::Location destination = this->arena->getPacman()->getNextLocation(this->arena->getSize());

			if(!this->arena->detectWallCollision(destination))
			{
				this->arena->movePacman(destination);
				if(this->arena->getWall(destination)->getType() == DOT_WALL)
				{
					this->gameInfo->addScore(this->arena->getWall(destination)->getValue());
					this->arena->getWall(destination)->setType(EMPTY_WALL);
					this->arena->getWall(destination)->setValue(0);
				}

				if(this->arena->detectGhostCollision() && !Settings::Config::getInstance().getValueOfKey<bool>(Settings::GOD_MODE))
				{
					cout << "GAME OVER" << endl;
				}
			}
			else
			{
				this->arena->getPacman()->setMoving(false);
			}
		}
	}

	const shared_ptr<Pacman> Gamemanager::getPacman() noexcept
	{
		return this->arena->getPacman();
	}

	const shared_ptr<Arena> Gamemanager::getArena() noexcept
	{
		return this->arena;
	}
}

