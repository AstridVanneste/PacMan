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
#include <SDL2/SDL_ttf.h>

#include "../../Util/Direction.h"
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
	shared_ptr<SDL_Texture> dot;

	shared_ptr<TTF_Font> font;

public:
	TextureManager();
	TextureManager(shared_ptr<SDL_Renderer> renderer);
	virtual ~TextureManager();

	static TextureManager& getInstance();

	void setRenderer(shared_ptr<SDL_Renderer> renderer) noexcept;

	shared_ptr<SDL_Texture> getBackground() noexcept;
	shared_ptr<SDL_Texture> getGhost() noexcept;
	shared_ptr<SDL_Texture> getPacman() noexcept;

	shared_ptr<SDL_Texture> getText(string text) noexcept;
};

} /* namespace Game */

#endif /* SDL_UTIL_TEXTUREMANAGER_H_ */
