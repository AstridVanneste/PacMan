/*
 * Game.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef GAME_H_
#define GAME_H_
#include "GraphicsHandler.h"
#include "Util/AbstractFactory.h"

namespace Game
{
	class Gamemanager
	{
	private:
		AbstractFactory* factory;
		bool running;

		Gamemanager();
		Gamemanager(const Gamemanager& gamemanager) = delete;
		Gamemanager* operator =(const Gamemanager& gamemanager) = delete;

		void run();
	public:
		virtual ~Gamemanager();

		static Gamemanager& getInstance();

		void setFactory(AbstractFactory* factory);
		AbstractFactory* getFactory();

		void start();
		bool isRunning();
	};
}

#endif /* GAME_H_ */
