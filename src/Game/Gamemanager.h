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
#include "EventHandler.h"
#include "Map.h"

namespace Game
{
	const unsigned int FPS = 60;
	const unsigned int FRAME_DELAY = 1000/FPS;
	class Gamemanager
	{
	private:
		shared_ptr<AbstractFactory> factory;
		shared_ptr<Map> map;
		shared_ptr<Event_Handler> eventHandler;

		bool running;

		Gamemanager();
		Gamemanager(const Gamemanager& gamemanager) = delete;
		Gamemanager* operator =(const Gamemanager& gamemanager) = delete;

		void run();
	public:
		virtual ~Gamemanager();

		static Gamemanager& getInstance();

		void setFactory(shared_ptr<AbstractFactory> factory) noexcept;
		const shared_ptr<AbstractFactory> getFactory() noexcept;

		void start();
		bool isRunning();

		void update();
	};
}

#endif /* GAME_H_ */
