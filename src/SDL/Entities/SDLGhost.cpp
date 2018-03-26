/*
 * SDLGhost.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */
#include <iostream>
#include <memory>
#include "SDLGhost.h"
#include "../SDLGraphHandler.h"
#include "../Util/SDLDestroyer.h"
#include "../Util/TextureManaging.h"
#include "../Util/TextureManager.h"
using namespace std;

namespace SDL
{
	SDL_Ghost::SDL_Ghost()
	:Game::Ghost()
	{
	}

	SDL_Ghost::SDL_Ghost(Game::GhostType type)
	:Game::Ghost(type)
	{
	}

	SDL_Ghost::SDL_Ghost(Util::Location location, Game::GhostType type)
	:Game::Ghost(location, type)
	{
	}

	SDL_Ghost::~SDL_Ghost()
	{
	}

	SDL_Ghost& SDL_Ghost::operator=(const SDL_Ghost& g) noexcept
	{
		if(this != &g)
		{
			Ghost::operator =(g);
		}
		return *this;
	}

	const void SDL_Ghost::visualize()
	{
		//cout << "SDL_Ghost::visualize()" << endl;

		//cout << "visualize " << this->type  << " at ["<< this->location.x << "," << this->location.y << "]" << endl;
		shared_ptr<SDL_Renderer> renderer(SDL_Graph_Handler::getInstance().getRenderer());

		Util::Location imageOffset;
		imageOffset.x = this->type;
		imageOffset.y = this->direction%4;
		unique_ptr<SDL_Rect> srcR = createSrcRect(imageOffset);
		unique_ptr<SDL_Rect> destR = createDstRect(this->location);
		shared_ptr<SDL_Texture> tex = TextureManager::getInstance().getGhost();

		if(SDL_RenderCopy(renderer.get(), tex.get(), srcR.get(), destR.get())<0)
		{
			cout << "Error when drawing image on screen" << endl;
			cout << SDL_GetError() << endl;
		}
	}
}

