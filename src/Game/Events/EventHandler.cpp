/*
 * EventHandler.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: Astrid
 */

#include "EventHandler.h"
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
		cout << "KEY_DOWN detected" << endl;
		break;
	case KEY_UP:
		cout << "KEY_UP detected" << endl;
		break;
	case MOUSE:
		cout << "MOUSE detected" << endl;
		break;
	case WINDOW:
		cout << "WINDOW detected" << endl;
		break;
	}

	return false;
}

} /* namespace SDL */
