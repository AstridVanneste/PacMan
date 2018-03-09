/*
 * TextureManaging.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: Astrid
 */

#include "TextureManaging.h"
#include "SDLDestroyer.h"
#include "SDLDestroyShared.h"
#include <memory>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>

#include "SDLUtil.h"
using namespace std;

namespace SDL
{
	shared_ptr<SDL_Texture> createTexture(const char* path,shared_ptr<SDL_Renderer> renderer)
	{
		unique_ptr<SDL_Surface> surf(IMG_Load(path));
		if(surf == nullptr)
		{
			cout << "Error when loading surface " << path << endl;
			cout << IMG_GetError() << endl;
		}

		shared_ptr<SDL_Texture> tex = SDL_shared(SDL_CreateTextureFromSurface(renderer.get(), surf.get()));

		return tex;

	}

	unique_ptr<SDL_Rect> createRect(Location location)
	{
		unique_ptr<SDL_Rect> rect = make_unique<SDL_Rect>();
		rect->h = ENTITY_HEIGHT;
		rect->w = ENTITY_WIDTH;
		rect->x = location.y * (ENTITY_HEIGHT + 1);
		rect->y = location.x * (ENTITY_WIDTH + 1);
		return rect;
	}
}
