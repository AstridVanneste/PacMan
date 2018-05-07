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

	Event& operator=(const Event& e);

	EventType getType() const noexcept;
	void setType(const EventType& type) noexcept;

	string getSubtype() const noexcept;
	void setSubtype(const string& subtype) noexcept;
};

} /* namespace Game */

#endif /* GAME_EVENTS_EVENT_H_ */
