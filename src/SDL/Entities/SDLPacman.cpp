/*
 * SDLPacman.cpp
 *
 *  Created on: 10 mrt. 2018
 *      Author: Astrid
 */

#include "SDLPacman.h"
#include <memory>
#include <iostream>
#include <math.h>
#include "../Util/SDLUtil.h"
#include "../Util/TextureManaging.h"
#include "../Util/TextureManager.h"
#include "../SDLGraphHandler.h"
#include "../../Game/Entities/MovingEntity.h"

namespace SDL
{

	SDL_Pacman::SDL_Pacman()
	:Game::Pacman()
	{
	}

	SDL_Pacman::SDL_Pacman(const SDL_Pacman& pacman)
	:Game::Pacman(pacman)
	{
	}

	SDL_Pacman::SDL_Pacman(const Location& location)
	:Game::Pacman(location)
	{
	}

	SDL_Pacman::~SDL_Pacman()
	{
	}

	SDL_Pacman& SDL_Pacman::operator=(const SDL_Pacman& p)
	{
		if(this != &p)
		{
			Pacman::operator=(p);
		}
		return *this;
	}

	const void SDL_Pacman::visualize()
	{
		//stuff
		//cout << "visualize Pacman" << endl;
		shared_ptr<SDL_Renderer> renderer(SDL_Graph_Handler::getInstance().getRenderer());

		Location imageOffset;
		imageOffset.x = 0;
		imageOffset.y = this->direction%4;

		unique_ptr<SDL_Rect> srcR = createSrcRect(imageOffset);
		unique_ptr<SDL_Rect> destR = createDstRect(this->location);
		shared_ptr<SDL_Texture> tex = TextureManager::getInstance().getPacman();

		if(SDL_RenderCopy(renderer.get(), tex.get(), srcR.get(), destR.get())<0)
		{
			cout << "Error when drawing image on screen" << endl;
			cout << SDL_GetError() << endl;
		}
	}

} /* namespace Game */
