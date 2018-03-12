/*
 * Event.h
 *
 *  Created on: Mar 12, 2018
 *      Author: Astrid
 */

#ifndef GAME_EVENTS_EVENT_H_
#define GAME_EVENTS_EVENT_H_

#include "EventType.h"

namespace Game
{

class Event
{
private:
	EventType type;
public:
	Event();
	virtual ~Event();
};

} /* namespace Game */

#endif /* GAME_EVENTS_EVENT_H_ */
