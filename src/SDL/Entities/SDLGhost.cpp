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
#include "../Util/Util.h"
#include "../Util/SDLDestroyer.h"
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

		/*unique_ptr<SDL_Rect> dstRect;
		dstRect->h = ENTITY_HEIGHT;
		dstRect->w = ENTITY_WIDTH;
		dstRect->x = this->location.x * ENTITY_HEIGHT;
		dstRect->y = this->location.y * ENTITY_WIDTH;*/


		unique_ptr<SDL_Surface, SDL_Destroyer> tmpSurface(IMG_Load("res/Images/Inky.png"));
		if(tmpSurface == NULL)
		{
			cout << "Failed to load image to surface" << endl;
			cout << IMG_GetError()<< endl;
		}

		shared_ptr<SDL_Renderer> renderer(SDL_Graph_Handler::getInstance().getRenderer());
		unique_ptr<SDL_Texture, SDL_Destroyer> tex(SDL_CreateTextureFromSurface(renderer.get(), tmpSurface.get()));
		SDL_FreeSurface(tmpSurface.get());


		SDL_Rect* destrect = new SDL_Rect();
		destrect->h = 32;
		destrect->w = 32;
		destrect->x = this->location.x * 32;
		destrect->y = this->location.y * 32;

		if(SDL_RenderCopy(renderer.get(), tex.get(), NULL,destrect)<0)
		{
			cout << "Error when drawing image on screen" << endl;
			cout << SDL_GetError() << endl;
		}
		SDL_RenderPresent(renderer.get());
		SDL_Delay(3000);
	}
}

