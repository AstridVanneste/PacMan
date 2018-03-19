/*
 * Location.h
 *
 *  Created on: Mar 19, 2018
 *      Author: Astrid
 */

#ifndef GAME_UTIL_LOCATION_H_
#define GAME_UTIL_LOCATION_H_

#include <iostream>

#include "Direction.h"
using namespace std;

namespace Util
{

class Location
{
public:
	int x;
	int y;

	Location& operator=(const Location& l);

	friend Location operator+(const Location& l,Direction d) noexcept;

	friend ostream& operator<<(ostream& os, const Location& l);
};

} /* namespace Game */

#endif /* GAME_UTIL_LOCATION_H_ */
