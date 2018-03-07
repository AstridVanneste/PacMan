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
#include "../Game/GraphicsHandler.h"
using namespace std;

namespace SDL
{
	class SDL_Handler : public Game::Graphics_Handler
	{
	private:
		shared_ptr<SDL_Renderer> renderer;
		shared_ptr<SDL_Window> window;

		SDL_Handler();
		SDL_Handler(const SDL_Handler& h) = delete;
		SDL_Handler* operator= (const SDL_Handler& h) = delete;

	public:

		virtual ~SDL_Handler();

		static SDL_Handler& getInstance();

		shared_ptr<SDL_Renderer> getRenderer();
		shared_ptr<SDL_Window> getWindow();

		bool init();
		void delay(int time);
		bool visualizeAll();
		bool visualizeMap();
		bool visualizeComponent();
	};
}

#endif /* SDLHANDLER_H_ */
