/*
 * SDLManager.h
 *
 *  Created on: Feb 27, 2018
 *      Author: Astrid
 */

#ifndef SDLHANDLER_H_
#define SDLHANDLER_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <memory>
#include <string>

#include "../../Game/Control/Arena.h"
#include "../../Game/Control/GraphicsHandler.h"
using namespace std;

namespace SDL
{
	class SDL_Graph_Handler : public Game::GraphicsHandler
	{
	private:
		shared_ptr<SDL_Renderer> renderer;
		shared_ptr<SDL_Window> window;
		shared_ptr<Mix_Music> music;

		SDL_Graph_Handler();
		SDL_Graph_Handler(const SDL_Graph_Handler& h) = delete;
		SDL_Graph_Handler* operator= (const SDL_Graph_Handler& h) = delete;

	public:
		virtual ~SDL_Graph_Handler();

		static SDL_Graph_Handler& getInstance();

		const shared_ptr<SDL_Renderer> getRenderer() noexcept;
		const shared_ptr<SDL_Window> getWindow() noexcept;

		bool init(Util::Location size) noexcept;
		void delay(int time) noexcept override;
		unsigned int getTime() noexcept override;
		const bool visualizeAll() override;

		const bool playMusic() override;
	};
}

#endif /* SDLHANDLER_H_ */
