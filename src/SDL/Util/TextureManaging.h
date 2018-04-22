/*
 * TextureManaging.h
 *
 *  Created on: Mar 7, 2018
 *      Author: Astrid
 */

#ifndef SDL_ENTITIES_TEXTUREMANAGING_H_
#define SDL_ENTITIES_TEXTUREMANAGING_H_

#include <memory>
#include <string>
#include <SDL2/SDL.h>

#include "../../Util/Direction.h"
#include "../../Util/Location.h"
#include "SDLDestroyer.h"
using namespace std;

namespace SDL
{
	shared_ptr<SDL_Texture> createTexture(const char* path, shared_ptr<SDL_Renderer> renderer);
	unique_ptr<SDL_Rect> createDstRect(Util::Location location);
	unique_ptr<SDL_Rect> createDstRect(Util::Location, int offset, int speed, Util::Direction direction);
	unique_ptr<SDL_Rect> createSrcRect(Util::Location location);

	unique_ptr<SDL_Rect> createTextRect(Util::Location location, int length);
}

#endif /* SDL_ENTITIES_TEXTUREMANAGING_H_ */
