/*
 * EventHandler.h
 *
 *  Created on: Mar 7, 2018
 *      Author: Astrid
 */

#ifndef GAME_EVENTHANDLER_H_
#define GAME_EVENTHANDLER_H_

namespace Game
{

class Event_Handler
{
public:
	Event_Handler();
	virtual ~Event_Handler();

	virtual bool handleEvents()=0;
};

} /* namespace SDL */

#endif /* GAME_EVENTHANDLER_H_ */
