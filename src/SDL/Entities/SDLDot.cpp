/*
 * SDLDot.cpp
 *
 *  Created on: Mar 19, 2018
 *      Author: Astrid
 */

#include "SDLDot.h"
#include <memory>
#include <iostream>
#include <SDL2/SDL.h>
#include "../SDLGraphHandler.h"
#include "../Util/TextureManaging.h"
#include "../Util/TextureManager.h"

namespace SDL
{

SDL_Dot::SDL_Dot()
:Dot()
{
}

SDL_Dot::SDL_Dot(const Util::Location& location)
:Dot(location)
{
}

SDL_Dot::SDL_Dot(const Util::Location& location, int value)
:Dot(location, value)
{
}

SDL_Dot::~SDL_Dot()
{
}

const void SDL_Dot::visualize() noexcept
{
	shared_ptr<SDL_Renderer> renderer(SDL_Graph_Handler::getInstance().getRenderer());

	Util::Location offset;
	offset.x = IMAGE_OFFSET[0];
	offset.y = IMAGE_OFFSET[1];
	unique_ptr<SDL_Rect> srcR = createSrcRect(offset);
	unique_ptr<SDL_Rect> destR = createDstRect(this->location);
	shared_ptr<SDL_Texture> tex = TextureManager::getInstance().getBackground();

	if(SDL_RenderCopy(renderer.get(), tex.get(), srcR.get() ,destR.get())<0)
	{
		cout << "Error when drawing image on screen" << endl;
		cout << SDL_GetError() << endl;
	}
}

} /* namespace SDL */
