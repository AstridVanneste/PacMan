/*
 * EventHandler.h
 *
 *  Created on: Mar 7, 2018
 *      Author: Astrid
 */

#ifndef GAME_EVENTHANDLER_H_
#define GAME_EVENTHANDLER_H_

#include <vector>
#include <memory>
#include "Event.h"
using namespace std;

namespace Game
{

class Event_Handler
{
private:
	void keyDown(shared_ptr<Event> event) noexcept;
protected:
	vector<shared_ptr<Event>> events;
public:
	Event_Handler();
	virtual ~Event_Handler();

	bool handleEvent(shared_ptr<Event> event);
	bool handleEvents();
	virtual void pollEvents()=0;
};

} /* namespace SDL */

#endif /* GAME_EVENTHANDLER_H_ */
