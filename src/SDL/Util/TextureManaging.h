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
#include "../../Game/Util/Util.h"
using namespace std;

unique_ptr<SDL_Texture> createTexture(const char* path,Location imageOffset,Location destination);

#endif /* SDL_ENTITIES_TEXTUREMANAGING_H_ */
