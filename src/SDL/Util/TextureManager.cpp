/*
 * TextureManager.cpp
 *
 *  Created on: 9 mrt. 2018
 *      Author: Astrid
 */

#include "TextureManager.h"
#include "TextureManaging.h"
#include "../../Settings/Config.h"
#include "SDLDestroyShared.h"
#include "SDLDestroyer.h"
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
				this->walls = createTexture(path.c_str(), this->renderer);
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
				this->ghosts = createTexture(path.c_str(), this->renderer);
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
				this->pacman = createTexture(path.c_str(), this->renderer);
			}
		}
		return this->pacman;
	}

	shared_ptr<SDL_Texture> TextureManager::getText(string text) noexcept
	{
		if(this->font.get() == nullptr)
		{
			string path = Settings::Config::getInstance().getValueOfKey<string>(Settings::FONT_PATH);
			int size = Settings::Config::getInstance().getValueOfKey<int>(Settings::FONT_SIZE);
			this->font = SDL_shared<TTF_Font>(TTF_OpenFont(path.c_str(), size));
		}

		unsigned char r = 255 - Settings::Config::getInstance().getValueOfKey<int>(Settings::B_R);
		unsigned char g = 255 - Settings::Config::getInstance().getValueOfKey<int>(Settings::B_G);
		unsigned char b = 255 - Settings::Config::getInstance().getValueOfKey<int>(Settings::B_B);
		unsigned char a = Settings::Config::getInstance().getValueOfKey<int>(Settings::B_A);

		SDL_Color color = {r, g, b, a};

		unique_ptr<SDL_Surface, SDL_Destroyer> surface(TTF_RenderText_Solid(font.get(), text.c_str(), color));

		shared_ptr<SDL_Texture> texture = SDL_shared<SDL_Texture>(SDL_CreateTextureFromSurface(this->renderer.get(), surface.get()));

		return texture;
	}

} /* namespace Game */
