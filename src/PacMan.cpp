

#include "Game/Control/Gamemanager.h"
#include <iostream>
#include <memory>
#include "Game/Control/AbstractFactory.h"
#include "SDL/Control/SDLFactory.h"
using namespace std;

int main(int argc, char *argv[])
{
	Game::Gamemanager::getInstance().setFactory(make_shared<SDL::SDL_Factory>());
	Game::Gamemanager::getInstance().start();

	//cout << "THE END" << endl;
	return 0;
}
