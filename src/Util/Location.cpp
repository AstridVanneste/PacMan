/*
 * Location.cpp
 *
 *  Created on: Mar 19, 2018
 *      Author: Astrid
 */

#include "Location.h"

namespace Util
{

Location& Location::operator =(const Location& l)
{
	if(this != &l)
	{
		this->x = l.x;
		this->y = l.y;
	}
	return *this;
}

Location operator+(const Location& l, Direction d) noexcept
{
	Location loc = l;

	switch(d)
	{
	case UP:
		loc.x--;
		break;
	case DOWN:
		loc.x++;
		break;
	case LEFT:
		loc.y--;
		break;
	case RIGHT:
		loc.y++;
		break;
	default:
		break;
	}

	return loc;
}

Location operator+=(const Location& l, Direction d) noexcept
{
	return operator+(l,d);
}

ostream& operator << (ostream& os, const Location& l)
{
	os << "[" << l.x << "," << l.y << "]";
	return os;
}

bool operator==(const Location& l1, const Location& l2) noexcept
{
	return (l1.x == l2.x) && (l1.y == l2.y);
}

} /* namespace Game */
