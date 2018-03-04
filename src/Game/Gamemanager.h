/*
 * Game.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef GAME_H_
#define GAME_H_
#include "../GraphicsHandler.h"
#include "Util/AbstractFactory.h"

namespace Game
{
	class Gamemanager
	{
	private:
		AbstractFactory* factory;
		Graphics_Handler* graphicsHandler;
		bool running;

		static Gamemanager* instance;

		Gamemanager();

	public:
		virtual ~Gamemanager();

		static Gamemanager* getInstance();

		void setFactory(AbstractFactory* factory);
		void setGraphicsHandler(Graphics_Handler* graphicsHandler);
		AbstractFactory* getFactory();
		Graphics_Handler* getGraphicsHandler();

		void start();
		bool isRunning();
	};
}

#endif /* GAME_H_ */
