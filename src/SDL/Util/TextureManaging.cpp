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

	unique_ptr<SDL_Rect> createDstRect(Util::Location location)
	{
		unique_ptr<SDL_Rect> rect = make_unique<SDL_Rect>();
		rect->h = ENTITY_HEIGHT;
		rect->w = ENTITY_WIDTH;
		rect->x = location.y * ENTITY_WIDTH;
		rect->y = location.x * ENTITY_HEIGHT + ARENA_OFFSET;
		return rect;
	}

	unique_ptr<SDL_Rect> createDstRect(Util::Location location, int offset, int speed, Util::Direction direction)
	{
		unique_ptr<SDL_Rect> rect = createDstRect(location);
		offset -= speed/2;

		float factor;

		if(direction == Util::UP || direction == Util::DOWN)
		{
			// ADJUST x
			factor = ENTITY_HEIGHT/speed;
			float result = factor * offset;
			if(direction == Util::DOWN)
			{
				rect->y += (int)result;
			}
			else
			{
				rect->y -= (int)result;
			}

		}
		else
		{
			// ADJUST y
			factor = ENTITY_WIDTH/speed;
			float result = factor * offset;
			if(direction == Util::RIGHT)
			{
				rect->x += (int)result;
			}
			else
			{
				rect->x -= (int)result;
			}
		}

		return rect;
	}

	unique_ptr<SDL_Rect> createSrcRect(Util::Location location)
	{
		unique_ptr<SDL_Rect> rect = make_unique<SDL_Rect>();
		rect->h = ENTITY_HEIGHT;
		rect->w = ENTITY_WIDTH;
		rect->x = location.y * (ENTITY_HEIGHT + 1);
		rect->y = location.x * (ENTITY_WIDTH + 1);
		return rect;
	}

	unique_ptr<SDL_Rect> createTextRect(Util::Location location)
	{
		unique_ptr<SDL_Rect> rect = make_unique<SDL_Rect>();
		rect->h = TEXT_HEIGHT;
		rect->w = TEXT_WIDTH;
		rect->x = location.y;
		rect->y = location.x;

		return rect;
	}
}
