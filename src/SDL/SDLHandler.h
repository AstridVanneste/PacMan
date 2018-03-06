/*
 * SDLManager.h
 *
 *  Created on: Feb 27, 2018
 *      Author: Astrid
 */

#ifndef SDLHANDLER_H_
#define SDLHANDLER_H_
#include <SDL2/SDL.h>
#include <string>
#include "../Game/GraphicsHandler.h"
using namespace std;

namespace SDL
{
	class SDL_Handler : public Game::Graphics_Handler
	{
	private:
		SDL_Renderer* renderer;
		SDL_Window* window;

		SDL_Handler();
		SDL_Handler(const SDL_Handler& h) = delete;
		SDL_Handler* operator= (const SDL_Handler& h) = delete;

	public:

		virtual ~SDL_Handler();

		static SDL_Handler& getInstance();

		SDL_Renderer* getRenderer();
		SDL_Window* getWindow();

		bool init();
		void delay(int time);
		bool visualizeAll();
		bool visualizeMap();
		bool visualizeComponent();
	};
}

#endif /* SDLHANDLER_H_ */
