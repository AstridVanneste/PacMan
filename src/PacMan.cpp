//============================================================================
// Name        : PacMan.cpp
// Author      : Astrid Vanneste
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Game/Gamemanager.h"
#include "Game/Util/AbstractFactory.h"
#include "SDL/Util/SDLFactory.h"

int main()
{
	Game::AbstractFactory *factory = new SDL::SDL_Factory();
	Game::Gamemanager *gamemanager = Game::Gamemanager::getInstance();
	gamemanager->setFactory(factory);

	gamemanager->start();
	return 0;
}
