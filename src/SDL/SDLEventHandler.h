/*
 * SDLEventHandler.h
 *
 *  Created on: Mar 7, 2018
 *      Author: Astrid
 */

#ifndef SDL_SDLEVENTHANDLER_H_
#define SDL_SDLEVENTHANDLER_H_
#include "../Game/EventHandler.h"

namespace SDL
{

	class SDL_Event_Handler : public Game::Event_Handler
	{
	public:
		SDL_Event_Handler();
		virtual ~SDL_Event_Handler();

		bool handleEvents();
	};

} /* namespace SDL */

#endif /* SDL_SDLEVENTHANDLER_H_ */
