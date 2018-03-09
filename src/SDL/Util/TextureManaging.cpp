/*
 * TextureManaging.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: Astrid
 */

#include "TextureManaging.h"
#include "SDLDestroyer.h"
#include <memory>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include "Util.h"
using namespace std;

namespace SDL
{
	unique_ptr<SDL_Texture, SDL_Destroyer> createTexture(const char* path,shared_ptr<SDL_Renderer> renderer)
	{
		unique_ptr<SDL_Surface, SDL_Destroyer> surf(IMG_Load(path));
		if(surf == nullptr)
		{
			cout << "Error when loading surface " << path << endl;
			cout << IMG_GetError() << endl;
		}

		unique_ptr<SDL_Texture, SDL_Destroyer> tex(SDL_CreateTextureFromSurface(renderer.get(), surf.get()));
		return tex;

	}

	unique_ptr<SDL_Rect> createRect(Location location)
	{
		unique_ptr<SDL_Rect> rect = make_unique<SDL_Rect>();
		rect->h = ENTITY_HEIGHT;
		rect->w = ENTITY_WIDTH;
		rect->x = location.x * (ENTITY_HEIGHT + 1);
		rect->y = location.y * (ENTITY_WIDTH + 1);
		return rect;
	}
}
