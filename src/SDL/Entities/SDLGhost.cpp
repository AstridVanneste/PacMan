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

	SDL_Ghost::~SDL_Ghost()
	{
	}

	void SDL_Ghost::visualize()
	{
		cout << "SDL_Ghost::visualize()" << endl;

		shared_ptr<SDL_Renderer> renderer(SDL_Graph_Handler::getInstance().getRenderer());

		unique_ptr<SDL_Rect> destR = createRect(this->location);
		shared_ptr<SDL_Texture> tex = createTexture("res/Images/Clyde.png", renderer);

		if(SDL_RenderCopy(renderer.get(), tex.get(), NULL,destR.get())<0)
		{
			cout << "Error when drawing image on screen" << endl;
			cout << SDL_GetError() << endl;
		}
		SDL_RenderPresent(renderer.get());
	}
}

