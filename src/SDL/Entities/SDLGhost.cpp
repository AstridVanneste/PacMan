/*
 * SDLGhost.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */
#include <iostream>
#include "SDLGhost.h"
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
		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_Window *window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
		SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

		SDL_Surface* tmpSurface = IMG_Load("res/Images/PacMan.png");
		if(tmpSurface == NULL)
		{
			cout << "Failed to load image to surface" << endl;
			cout << IMG_GetError()<< endl;
		}
		SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0,  255);
		SDL_RenderClear(renderer);

		SDL_Rect* destrect = new SDL_Rect;
		destrect->h = 32;
		destrect->w = 32;
		destrect->x = 0;
		destrect->y = 0;

		if(SDL_RenderCopy(renderer, tex, NULL,destrect)<0)
		{
			cout << "Error when drawing image on screen" << endl;
			cout << SDL_GetError() << endl;
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(3000);
	}
}

