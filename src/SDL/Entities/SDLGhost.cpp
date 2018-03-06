/*
 * SDLGhost.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */
#include <iostream>
#include <memory>
#include "SDLGhost.h"
#include "../SDLHandler.h"
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
		// TODO Auto-generated destructor stub
	}

	void SDL_Ghost::visualize()
	{
		cout << "SDL_Ghost::visualize()" << endl;

		unique_ptr<SDL_Rect> srcRect();
		srcRect->h = ;
		srcRect->w =





		SDL_Surface* tmpSurface = IMG_Load("res/Images/PacMan.png");
		if(tmpSurface == NULL)
		{
			cout << "Failed to load image to surface" << endl;
			cout << IMG_GetError()<< endl;
		}

		SDL_Renderer* renderer = SDL_Handler::getInstance().getRenderer();

		SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);


		SDL_Rect* destrect = new SDL_Rect();
		destrect->h = 32;
		destrect->w = 32;
		destrect->x = this->location.x * 32;
		destrect->y = this->location.y * 32;

		if(SDL_RenderCopy(renderer, tex, NULL,destrect)<0)
		{
			cout << "Error when drawing image on screen" << endl;
			cout << SDL_GetError() << endl;
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(3000);
	}
}

