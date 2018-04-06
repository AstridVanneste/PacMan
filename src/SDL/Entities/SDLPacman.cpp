/*
 * SDLPacman.cpp
 *
 *  Created on: 10 mrt. 2018
 *      Author: Astrid
 */

#include "SDLPacman.h"
#include <memory>
#include <iostream>
#include <math.h>
#include "../Util/SDLUtil.h"
#include "../Util/TextureManaging.h"
#include "../Util/TextureManager.h"
#include "../Control/SDLGraphHandler.h"
#include "../../Game/Entities/MovingEntity.h"

namespace SDL
{

	SDL_Pacman::SDL_Pacman()
	:Game::Pacman()
	{
		this->animationOffset = 0;
		this->animationDirection = true;
	}

	SDL_Pacman::SDL_Pacman(const SDL_Pacman& pacman)
	:Game::Pacman(pacman)
	{
		this->animationOffset = pacman.animationOffset;
		this->animationDirection = pacman.animationDirection;
	}

	SDL_Pacman::SDL_Pacman(const Util::Location& location)
	:Game::Pacman(location)
	{
		this->animationOffset = 0;
		this->animationDirection = true;
	}

	SDL_Pacman::~SDL_Pacman()
	{
	}

	SDL_Pacman& SDL_Pacman::operator=(const SDL_Pacman& p) noexcept
	{
		if(this != &p)
		{
			Pacman::operator=(p);
			this->animationOffset = p.animationOffset;
			this->animationDirection = p.animationDirection;
		}
		return *this;
	}

	const void SDL_Pacman::visualize()
	{
		//stuff
		//cout << "visualize Pacman" << endl;

		if(this->offset%(this->speed/2) == this->speed%(this->speed/2))
		{
			if((this->animationOffset >= MAX_ANIMATION && this->animationDirection) || (this->animationOffset <= 0 && !this->animationDirection))
			{
				this->animationDirection = !this->animationDirection;
			}
			else if(this->animationDirection)
			{
				this->animationOffset++;
			}
			else
			{
				this->animationOffset--;
			}
		}

		shared_ptr<SDL_Renderer> renderer(SDL_Graph_Handler::getInstance().getRenderer());

		Util::Location imageOffset;
		imageOffset.x = this->animationOffset;
		imageOffset.y = this->direction%4;

		unique_ptr<SDL_Rect> srcR = createSrcRect(imageOffset);
		unique_ptr<SDL_Rect> destR;
		if(this->moving)
		{
			 destR = createDstRect(this->location, this->offset, this->speed, this->direction);
		}
		else
		{
			destR = createDstRect(this->location);
		}
		shared_ptr<SDL_Texture> tex = TextureManager::getInstance().getPacman();

		if(SDL_RenderCopy(renderer.get(), tex.get(), srcR.get(), destR.get())<0)
		{
			cout << "Error when drawing image on screen" << endl;
			cout << SDL_GetError() << endl;
		}
	}

} /* namespace Game */
