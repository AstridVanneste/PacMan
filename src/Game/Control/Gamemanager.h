/*
 * Game.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef GAME_H_
#define GAME_H_
#include <memory>

#include "Arena.h"
#include "GraphicsHandler.h"
#include "AbstractFactory.h"
#include "../Events/EventHandler.h"
#include "GameInfo.h"

namespace Game
{
	const unsigned int FPS = 60;
	const unsigned int FRAME_DELAY = 1000/FPS;

	class Gamemanager
	{
	private:
		shared_ptr<AbstractFactory> factory;
		shared_ptr<Arena> arena;
		shared_ptr<EventHandler> eventHandler;
		shared_ptr<GameInfo> gameInfo;

		bool running;

		Gamemanager();
		Gamemanager(const Gamemanager& gamemanager) = delete;
		Gamemanager* operator = (const Gamemanager& gamemanager) = delete;

		void run();
	public:
		virtual ~Gamemanager();

		static Gamemanager& getInstance();

		void setFactory(shared_ptr<AbstractFactory> factory) noexcept;
		shared_ptr<AbstractFactory> getFactory() const noexcept;

		shared_ptr<GameInfo> getGameInfo() const noexcept;

		shared_ptr<Arena> getArena() const noexcept;

		shared_ptr<Pacman> getPacman() const noexcept;

		void handleGhostCollision() noexcept;

		void start();
		bool isRunning();

		void update();
	};
}

#endif /* GAME_H_ */
