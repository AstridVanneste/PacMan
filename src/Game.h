/*
 * Game.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef GAME_H_
#define GAME_H_
#include "AbstractFactory.h"
#include "GraphicsHandler.h"

class Game
{
private:
	AbstractFactory* factory;
	Graphics_Handler* graphicsHandler;
	bool running;

	static Game* instance;

	Game();

public:

	virtual ~Game();

	static Game* getInstance();

	void setFactory(AbstractFactory* factory);
	void setGraphicsHandler(Graphics_Handler* graphicsHandler);
	AbstractFactory* getFactory();
	Graphics_Handler* getGraphicsHandler();

	void start();
	bool isRunning();
};

#endif /* GAME_H_ */
