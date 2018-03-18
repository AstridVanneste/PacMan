/*
 * Event.h
 *
 *  Created on: Mar 12, 2018
 *      Author: Astrid
 */

#ifndef GAME_EVENTS_EVENT_H_
#define GAME_EVENTS_EVENT_H_

#include "EventType.h"
#include <string>
using namespace std;

namespace Game
{

class Event
{
private:
	EventType type;
	string subtype;
public:
	Event();
	Event(const EventType& type, const string& subtype);
	virtual ~Event();

	const EventType getType() noexcept;
	void setType(const EventType& type) noexcept;

	const string getSubtype() noexcept;
	void setSubtype(const string& subtype) noexcept;
};

} /* namespace Game */

#endif /* GAME_EVENTS_EVENT_H_ */
