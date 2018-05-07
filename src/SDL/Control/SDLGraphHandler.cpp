/*
 * SDLManager.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: Astrid
 */

#include <vector>
#include <string>
#include <cstring>
#include <SDL2/SDL_TTF.h>
#include "SDLGraphHandler.h"
#include "../../Game/Control/Gamemanager.h"
#include "../Util/TextureManager.h"
#include "../Util/SDLDestroyShared.h"
#include "../../Settings/Config.h"
using namespace std;

namespace SDL
{
	SDL_Graph_Handler::SDL_Graph_Handler()
	{
		this->window = NULL;
		this->renderer = NULL;
	}

	SDL_Graph_Handler::~SDL_Graph_Handler()
	{

	}

	SDL_Graph_Handler& SDL_Graph_Handler::getInstance()
	{
		static SDL_Graph_Handler instance;
		return instance;
	}

	/*
	 * Returns a pointer to the window used by this manager.
	 */
	shared_ptr<SDL_Window> SDL_Graph_Handler::getWindow() const noexcept
	{
		return this->window;
	}

	/*
	 * Returns a pointer to the renderer used by this manager.
	 */
	shared_ptr<SDL_Renderer> SDL_Graph_Handler::getRenderer() const noexcept
	{
		return this->renderer;
	}


	/*
	 * Initializes everything necessary to start using SDL and the specific
	 * window and renderer of this manager.
	 */
	bool SDL_Graph_Handler::init(Util::Location size) noexcept
	{
		if(SDL_Init(SDL_INIT_EVERYTHING)==0)
		{
			atexit(SDL_Quit);
			int height = Settings::Config::getInstance().getValueOfKey<int>(Settings::ENTITY_HEIGHT);
			int width = Settings::Config::getInstance().getValueOfKey<int>(Settings::ENTITY_WIDTH);
			int offset = Settings::Config::getInstance().getValueOfKey<int>(Settings::ARENA_OFFSET);
			this->window = SDL_shared<SDL_Window> (SDL_CreateWindow("PacMan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.y * width, size.x* height + offset, SDL_WINDOW_SHOWN));
			this->renderer = SDL_shared<SDL_Renderer>(SDL_CreateRenderer(window.get(), -1, 0));
		}
		else
		{
			return false;
		}

		if(TTF_Init()==0)
		{
			atexit(TTF_Quit);
			if(this->window != NULL && this->renderer != NULL)
			{
				TextureManager::getInstance().setRenderer(this->renderer);
			}
		}
		else
		{
			cout << "TTF not properly initialized!" << endl;
			return false;
		}

		//Initialize SDL_mixer
		if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == 0 )
		{
			// TODO change to settings constant
			string path = Settings::Config::getInstance().getValueOfKey<string>(Settings::MUSIC_PATH);
			this->music = SDL_shared<Mix_Music>(Mix_LoadMUS(path.c_str()));
			if(this->music == nullptr)
			{
				return false;
			}
			Mix_VolumeMusic(MIX_MAX_VOLUME * Settings::Config::getInstance().getValueOfKey<float>(Settings::MUSIC_VOLUME));
		}
		else
		{
			return false;
		}

		return true;
	}

	void SDL_Graph_Handler::delay(int time) noexcept
	{
		SDL_Delay(time);
	}

	unsigned int SDL_Graph_Handler::getTime() noexcept
	{
		return SDL_GetTicks();
	}

	bool SDL_Graph_Handler::visualizeAll() const
	{
		int r = Settings::Config::getInstance().getValueOfKey<int>(Settings::B_R);
		int g = Settings::Config::getInstance().getValueOfKey<int>(Settings::B_G);
		int b = Settings::Config::getInstance().getValueOfKey<int>(Settings::B_B);
		int a = Settings::Config::getInstance().getValueOfKey<int>(Settings::B_A);
		SDL_SetRenderDrawColor(renderer.get(), r, g, b,  a);
		SDL_RenderClear(renderer.get());

		Game::Gamemanager::getInstance().getArena()->visualize();
		Game::Gamemanager::getInstance().getGameInfo()->visualize();

		SDL_RenderPresent(this->renderer.get());

		return true;
	}

	bool SDL_Graph_Handler::playMusic() const
	{
		//If there is no music playing
		if( Mix_PlayingMusic() == 0 )
		{
			//Play the music
			if( Mix_PlayMusic( music.get(), -1 ) == -1 )
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
}


