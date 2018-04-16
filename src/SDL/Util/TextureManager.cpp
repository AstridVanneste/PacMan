/*
 * TextureManager.cpp
 *
 *  Created on: 9 mrt. 2018
 *      Author: Astrid
 */

#include "TextureManager.h"
#include "TextureManaging.h"
#include "../../Settings/Config.h"
#include <cstring>
#include <string>
using namespace std;

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
				//cout << "Wall texture created" << endl;
				string path = Settings::Config::getInstance().getValueOfKey<string>(Settings::WALL_PATH);
				this->walls = createTexture(path.c_str(), renderer);
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
				//cout << "Ghost texture created" << endl;
				string path = Settings::Config::getInstance().getValueOfKey<string>(Settings::GHOST_PATH);
				this->ghosts = createTexture(path.c_str(), renderer);
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
				//cout << "Pacman texture created" << endl;
				string path = Settings::Config::getInstance().getValueOfKey<string>(Settings::PACMAN_PATH);
				this->pacman = createTexture(path.c_str(), renderer);
			}
		}
		return this->pacman;
	}

} /* namespace Game */
