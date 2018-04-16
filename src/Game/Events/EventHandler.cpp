/*
 * EventHandler.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: Astrid
 */

#include "EventHandler.h"
#include "../Control/Gamemanager.h"
#include <iostream>
using namespace std;

namespace Game
{

Event_Handler::Event_Handler()
{
}

Event_Handler::~Event_Handler()
{
}

Event_Handler& Event_Handler::operator=(const Event_Handler& eh)
{
	return *this;
}

bool Event_Handler::handleEvents()
{
	this->pollEvents();

	bool quit = false;

	while(this->events.size() != 0)
	{
		if(this->handleEvent(this->events.back()))
		{
			quit = true;
		}


		this->events.pop_back();
	}
	return quit;
}

bool Event_Handler::handleEvent(shared_ptr<Event> event)
{
	switch(event->getType())
	{
	case QUIT:
		return true;
	case KEY_DOWN:
		//cout << "KEY_DOWN detected" << endl;
		this->keyDown(event);
		break;
	case KEY_UP:
		//cout << "KEY_UP detected" << endl;
		break;
	case MOUSE:
		//cout << "MOUSE detected" << endl;
		break;
	case WINDOW:
		//cout << "WINDOW detected" << endl;
		break;
	}

	return false;
}

void Event_Handler::keyDown(shared_ptr<Event> event) noexcept
{
	string subtype = event->getSubtype();

	if(Gamemanager::getInstance().getGameInfo()->getGameState() == NOT_STARTED)
	{
		Gamemanager::getInstance().getGameInfo()->setGameState(RUNNING);
	}

	if(Gamemanager::getInstance().getGameInfo()->getGameState() != PAUSED)
	{
		if(subtype == UP_K)
		{
			Gamemanager::getInstance().getPacman()->setNextDirection(Util::UP);
			//cout << "KEY UP" << endl;
		}
		else if (subtype == DOWN_K)
		{
			Gamemanager::getInstance().getPacman()->setNextDirection(Util::DOWN);
			//cout << "KEY DOWN" << endl;
		}
		else if(subtype == LEFT_K)
		{
			Gamemanager::getInstance().getPacman()->setNextDirection(Util::LEFT);
			//cout << "KEY LEFT" << endl;
		}
		else if(subtype == RIGHT_K)
		{
			Gamemanager::getInstance().getPacman()->setNextDirection(Util::RIGHT);
			//cout << "KEY RIGHT" << endl;
		}
	}
	if(subtype == ESCAPE_K)
	{
		Gamemanager::getInstance().getGameInfo()->togglePause();
		//cout << subtype << endl;
	}

}

} /* namespace SDL */
