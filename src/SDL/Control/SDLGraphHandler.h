/*
 * SDLManager.h
 *
 *  Created on: Feb 27, 2018
 *      Author: Astrid
 */

#ifndef SDLHANDLER_H_
#define SDLHANDLER_H_
#include <SDL2/SDL.h>
#include <memory>
#include <string>

#include "../../Game/Control/Arena.h"
#include "../../Game/Control/GraphicsHandler.h"
using namespace std;

namespace SDL
{
	class SDL_Graph_Handler : public Game::Graphics_Handler
	{
	private:
		shared_ptr<SDL_Renderer> renderer;
		shared_ptr<SDL_Window> window;

		SDL_Graph_Handler();
		SDL_Graph_Handler(const SDL_Graph_Handler& h) = delete;
		SDL_Graph_Handler* operator= (const SDL_Graph_Handler& h) = delete;

	public:
		//TODO const and noexcept markings
		//TODO is singleton usefull?
		virtual ~SDL_Graph_Handler();

		static SDL_Graph_Handler& getInstance();

		shared_ptr<SDL_Renderer> getRenderer();
		shared_ptr<SDL_Window> getWindow();

		bool init(Util::Location size);
		void quit() override;
		void delay(int time);
		unsigned int getTime();
		const bool visualizeAll() override;
	};
}

#endif /* SDLHANDLER_H_ */
