/*
 * EventType.h
 *
 *  Created on: Mar 12, 2018
 *      Author: Astrid
 */

#ifndef GAME_EVENTS_EVENTTYPE_H_
#define GAME_EVENTS_EVENTTYPE_H_

#include <string>
using namespace std;

namespace Game
{
	enum EventType
	{
		KEY_UP, KEY_DOWN, WINDOW, MOUSE, QUIT
	};

	const string LEFT_K = "LEFT";
	const string RIGHT_K = "RIGHT";
	const string UP_K = "UP";
	const string DOWN_K = "DOWN";

	const string ESCAPE_K = "ESCAPE";

	const string UNKNOWN_K = "UNKNOWN";
}

#endif /* GAME_EVENTS_EVENTTYPE_H_ */
