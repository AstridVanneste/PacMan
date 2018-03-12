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
	return this->pollEvents();
}

} /* namespace SDL */
