/*
 * Direction.cpp
 *
 *  Created on: 19 mrt. 2018
 *      Author: Astrid
 */

#include "Direction.h"
#include <iostream>
using namespace std;

namespace Util
{

	Direction inverseDirection(Direction d)
	{
		switch(d)
		{
		case UP:
			return DOWN;
		case DOWN:
			return UP;
		case LEFT:
			return RIGHT;
		case RIGHT:
			return LEFT;
		default:
			return NONE;
		}
	}


	ostream& operator<<(ostream& os, Direction d)
	{
		switch(d)
			{
			case UP:
				os << "UP";
				break;
			case DOWN:
				os << "DOWN";
				break;
			case LEFT:
				os << "LEFT";
				break;
			case RIGHT:
				os << "RIGHT";
				break;
			case NONE:
				os << "NONE";
				break;
			}
		return os;
	}
}


