/*
 * TextureManager.cpp
 *
 *  Created on: 9 mrt. 2018
 *      Author: Astrid
 */

#include "TextureManager.h"
#include "TextureManaging.h"
#include "../../Settings/Config.h"

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
			if(Settings::Config::getInstance().keyExists(Settings::WALL_PATH))
			{
				cout << "asking for wall path" << endl;
				char* path = Settings::Config::getInstance().getValueOfKey<char*>(Settings::WALL_PATH);
				cout << "WALLS PATH = [" << path << "]" << endl;
				this->walls = createTexture(path, this->renderer);
			}
		}
		return this->walls;
	}

	shared_ptr<SDL_Texture> TextureManager::getGhost() noexcept
	{
		if(this->ghosts.get() == nullptr)
		{
			if(Settings::Config::getInstance().keyExists(Settings::GHOST_PATH))
			{
				char* path = Settings::Config::getInstance().getValueOfKey<char*>(Settings::GHOST_PATH);
				this->ghosts = createTexture(path, renderer);
			}
		}
		return this->ghosts;
	}

	shared_ptr<SDL_Texture> TextureManager::getPacman() noexcept
	{
		if(this->pacman.get() == nullptr)
		{
			if(Settings::Config::getInstance().keyExists(Settings::PACMAN_PATH))
			{
				char* path = Settings::Config::getInstance().getValueOfKey<char*>(Settings::PACMAN_PATH);
				this->pacman = createTexture(path, renderer);
			}
		}

		return this->pacman;
	}

} /* namespace Game */
