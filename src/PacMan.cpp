//============================================================================
// Name        : PacMan.cpp
// Author      : Astrid Vanneste
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "AbstractFactory.h"
#include "SDLFactory.h"
#include "Game.h"

int main()
{
	AbstractFactory *factory = new SDL_Factory();
	Game *game = Game::getInstance();
	game->setFactory(factory);

	game->start();
	return 0;
}
