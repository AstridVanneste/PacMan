/*
 * TextureManager.h
 *
 *  Created on: 9 mrt. 2018
 *      Author: Astrid
 */

#ifndef SDL_UTIL_TEXTUREMANAGER_H_
#define SDL_UTIL_TEXTUREMANAGER_H_

#include <memory>
#include <SDL2/SDL.h>
#include "../../Game/Util/Util.h"
using namespace std;

namespace SDL
{

class TextureManager
{
private:
	shared_ptr<SDL_Renderer> renderer;

	shared_ptr<SDL_Texture> walls;
	shared_ptr<SDL_Texture> ghosts;
	shared_ptr<SDL_Texture> pacman;
public:
	TextureManager();
	TextureManager(shared_ptr<SDL_Renderer> renderer);
	virtual ~TextureManager();

	static TextureManager& getInstance();

	void setRenderer(shared_ptr<SDL_Renderer> renderer);

	shared_ptr<SDL_Texture> getWall();
	shared_ptr<SDL_Texture> getGhost();
	shared_ptr<SDL_Texture> getPacman();
};

} /* namespace Game */

#endif /* SDL_UTIL_TEXTUREMANAGER_H_ */
