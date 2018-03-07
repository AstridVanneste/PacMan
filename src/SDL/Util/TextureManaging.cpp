/*
 * TextureManaging.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: Astrid
 */

#include "TextureManaging.h"
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include "SDLDestroyer.h"
using namespace std;

namespace SDL
{
	unique_ptr<SDL_Texture> createTexture(const char* path,Location imageOffset,Location destination)
	{
		unique_ptr<SDL_Surface, SDL_Destroyer> surf(IMG_Load(path));
	}
}
