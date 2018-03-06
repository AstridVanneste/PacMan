//============================================================================
// Name        : PacMan.cpp
// Author      : Astrid Vanneste
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Game/Gamemanager.h"
#include <iostream>
#include <memory>
#include "Game/Util/AbstractFactory.h"
#include "SDL/Util/SDLFactory.h"
using namespace std;

int main(int argc, char *argv[])
{
	Game::Gamemanager::getInstance().setFactory(make_shared<SDL::SDL_Factory>());
	Game::Gamemanager::getInstance().start();

	cout << "THE END" << endl;
	return 0;
}
