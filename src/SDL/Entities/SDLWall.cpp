/*
 * SDLWall.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: Astrid
 */

#include "SDLWall.h"
#include <memory>
#include <iostream>
#include <SDL2/SDL.h>
#include "../SDLGraphHandler.h"
#include "../Util/TextureManaging.h"
#include "../Util/TextureManager.h"

namespace SDL
{

	SDL_Wall::SDL_Wall()
	: Game::Wall()
	{
	}

	SDL_Wall::SDL_Wall(const Util::Location& location)
	: Game::Wall(location)
	{
	}

	SDL_Wall::SDL_Wall(char type)
	: Game::Wall(type)
	{
	}

	SDL_Wall::SDL_Wall(const Util::Location& location, char type)
	: Game::Wall(location, type)
	{

	}

	SDL_Wall::SDL_Wall(const Util::Location& location, char type, int value)
	: Game::Wall(location, type, value)
	{

	}

	SDL_Wall::~SDL_Wall()
	{
	}

	SDL_Wall& SDL_Wall::operator=(const SDL_Wall& w)
	{
		if(this != &w)
		{
			Wall::operator=(w);
		}
		return *this;
	}

	const void SDL_Wall::visualize()
	{
		if(this->type != EMPTY_WALL)
		{
			shared_ptr<SDL_Renderer> renderer(SDL_Graph_Handler::getInstance().getRenderer());

			Util::Location offset;
			offset.x = WALL_IMAGE[this->type][0];
			offset.y = WALL_IMAGE[this->type][1];
			unique_ptr<SDL_Rect> srcR = createSrcRect(offset);
			unique_ptr<SDL_Rect> destR = createDstRect(this->location);
			shared_ptr<SDL_Texture> tex = TextureManager::getInstance().getBackground();

			if(SDL_RenderCopy(renderer.get(), tex.get(), srcR.get() ,destR.get())<0)
			{
				cout << "Error when drawing image on screen" << endl;
				cout << SDL_GetError() << endl;
			}

		}
	}

} /* namespace SDL */
