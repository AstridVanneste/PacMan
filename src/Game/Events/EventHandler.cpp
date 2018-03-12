/*
 * EventHandler.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: Astrid
 */

#include "EventHandler.h"

namespace Game
{

Event_Handler::Event_Handler()
{
}

Event_Handler::~Event_Handler()
{
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
		break;
	case KEY_UP:
		break;
	case MOUSE:
		break;
	case WINDOW:
		break;
	}

	return false;
}

} /* namespace SDL */
