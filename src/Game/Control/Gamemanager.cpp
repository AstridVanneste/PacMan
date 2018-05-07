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
		Settings::Config::getInstance().addPath("res/Settings/General.txt");
		Settings::Config::getInstance().addPath("res/Settings/Entities.txt");
		Settings::Config::getInstance().addPath("res/Settings/Graphics.txt");
		Settings::Config::getInstance().addPath("res/Settings/GamePhases.txt");

		//initialize game info
		this->gameInfo = this->factory->createGameInfo(0, Settings::Config::getInstance().getValueOfKey<int>(Settings::MAX_LIVES), NOT_STARTED);

		//initialize game arena
		this->arena->loadFromFile(Settings::Config::getInstance().getValueOfKey<string>(Settings::MAP_PATH));
		//cout << "Init graphics" << endl;
		this->factory->getGraphicsHandler().init(this->arena->getSize());

		// create event handler
		this->eventHandler = this->factory->createEventHandler();

		//play music
		if(Settings::Config::getInstance().getValueOfKey<bool>(Settings::MUSIC_ENABLE))
		{
			this->factory->getGraphicsHandler().playMusic();
		}


		//cout << "Start run()" << endl;
		this->run();
	}

	void Gamemanager::run()
	{
		bool end = false;
		while(!end)
		{
			unsigned int startTime = this->factory->getGraphicsHandler().getTime();

			//input
			end = this->eventHandler->handleEvents();

			//update positions
			if(this->gameInfo->getGameState() == RUNNING)
			{
				this->update();
			}

			//visualize
			this->factory->getGraphicsHandler().visualizeAll();
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

					if(this->arena->detectGhostCollision()  && (!Settings::Config::getInstance().getValueOfKey<bool>(Settings::GOD_MODE)))
					{
					//	this->handleGhostCollision();
					}

					this->arena->handleGhostCollision();
				}
			}
		}

		if(this->arena->getPacman()->update())
		{
			Util::Location destination = this->arena->getPacman()->getNextLocation(this->arena->getSize());

			if(!this->arena->detectWallCollision(destination))
			{
				this->arena->movePacman(destination);
				if(this->arena->getWall(destination)->getType() == DOT_WALL || this->arena->getWall(destination)->getType() == POWER_PELLET)
				{
					if(this->arena->getWall(destination)->getType() == POWER_PELLET)
					{
						this->arena->setFleeMode();
					}

					this->gameInfo->addScore(this->arena->getWall(destination)->getValue());
					this->gameInfo->decreaseDotsLeft();
					this->arena->getWall(destination)->setType(EMPTY_WALL);
					this->arena->getWall(destination)->setValue(0);
				}

				this->arena->handleGhostCollision();
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

	const shared_ptr<GameInfo> Gamemanager::getGameInfo() noexcept
	{
		return this->gameInfo;
	}

	void Gamemanager::handleGhostCollision() noexcept
	{
		this->gameInfo->decreaseLives();

		this->arena->getPacman()->respawn();
	}
}

