/*
 * Game.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef GAME_H_
#define GAME_H_
#include <memory>
#include "GraphicsHandler.h"
#include "Util/AbstractFactory.h"
#include "Map.h"

namespace Game
{
	class Gamemanager
	{
	private:
		//AbstractFactory* factory;
		//Map* map;

		shared_ptr<AbstractFactory> factory;
		shared_ptr<Map> map;

		bool running;

		Gamemanager();
		Gamemanager(const Gamemanager& gamemanager) = delete;
		Gamemanager* operator =(const Gamemanager& gamemanager) = delete;

		void run();
	public:
		virtual ~Gamemanager();

		static Gamemanager& getInstance();

		void setFactory(shared_ptr<AbstractFactory> factory);
		shared_ptr<AbstractFactory> getFactory();

		void start();
		bool isRunning();
	};
}

#endif /* GAME_H_ */
