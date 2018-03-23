/*
 * TextureManager.cpp
 *
 *  Created on: 9 mrt. 2018
 *      Author: Astrid
 */

#include "TextureManager.h"
#include "TextureManaging.h"

namespace SDL
{

	TextureManager::TextureManager()
	{
	}

	TextureManager::~TextureManager()
	{
	}

	TextureManager& TextureManager::getInstance()
	{
		static TextureManager instance;
		return instance;
	}

	void TextureManager::setRenderer(shared_ptr<SDL_Renderer> renderer) noexcept
	{
		this->renderer = renderer;
	}

	shared_ptr<SDL_Texture> TextureManager::getBackground() noexcept
	{
		if(this->walls.get() == nullptr)
		{
			this->walls = createTexture("res/Images/Walls.png", this->renderer);
		}

		return this->walls;
	}

	shared_ptr<SDL_Texture> TextureManager::getGhost() noexcept
	{
		if(this->ghosts.get() == nullptr)
		{
			this->ghosts = createTexture("res/Images/Ghost.png", renderer);
		}

		return this->ghosts;
	}

	shared_ptr<SDL_Texture> TextureManager::getPacman() noexcept
	{
		if(this->pacman.get() == nullptr)
		{
			this->pacman = createTexture("res/Images/Pacman.png", renderer);
		}

		return this->pacman;
	}

} /* namespace Game */
