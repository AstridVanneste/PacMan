/*
 * Game.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#include "Game.h"
#include "Ghost.h"

Game* Game::instance = 0;

Game::Game()
{
	this->factory = 0;
	this->graphicsHandler = 0;
}


Game* Game::getInstance()
{
	if(instance == 0)
	{
		instance = new Game();
	}
	return instance;
}

Game::~Game()
{
	delete this->factory;
	delete this->graphicsHandler;
}

void Game::start()
{
	//initialize game
	this->graphicsHandler = this->factory->createGraphicsHandler();


	Ghost* ghost = this->factory->createGhost();
	ghost->visualize();
}

AbstractFactory* Game::getFactory()
{
	return this->factory;
}

void Game::setFactory(AbstractFactory* factory)
{
	this->factory = factory;
}

Graphics_Handler* Game::getGraphicsHandler()
{
	return this->graphicsHandler;
}

void Game::setGraphicsHandler(Graphics_Handler* graphicsHandler)
{
	this->graphicsHandler = graphicsHandler;
}

