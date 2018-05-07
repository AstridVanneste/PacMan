/*
 * SDLEventHandler.h
 *
 *  Created on: Mar 7, 2018
 *      Author: Astrid
 */

#ifndef SDL_SDLEVENTHANDLER_H_
#define SDL_SDLEVENTHANDLER_H_
#include "../../Game/Events/EventHandler.h"

namespace SDL
{

	class SDL_Event_Handler : public Game::EventHandler
	{
	public:
		SDL_Event_Handler();
		virtual ~SDL_Event_Handler();

		SDL_Event_Handler& operator=(const SDL_Event_Handler& eh);

		void pollEvents();
	};

} /* namespace SDL */

#endif /* SDL_SDLEVENTHANDLER_H_ */
