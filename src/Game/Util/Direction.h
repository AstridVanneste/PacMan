#ifndef UTIL_H
#define UTIL_H

#include <iostream>
using namespace std;

enum Direction
	{
		LEFT , DOWN , RIGHT , UP, NONE
	};

Direction inverseDirection(Direction d);

ostream& operator << (ostream& os, Direction d);

#endif
