/*
 * Dot.h
 *
 *  Created on: Mar 19, 2018
 *      Author: Astrid
 */

#ifndef GAME_ENTITIES_DOT_H_
#define GAME_ENTITIES_DOT_H_

#include "Entity.h"

namespace Game
{

class Dot : public Entity
{
private:
	int value;
public:
	Dot();
	Dot(const Dot& dot);
	Dot(const Util::Location& location);
	Dot(const Util::Location& location, int value);

	//TODO = operator overloading
	Dot& operator=(const Dot& d);

	virtual ~Dot();
};

} /* namespace Game */

#endif /* GAME_ENTITIES_DOT_H_ */
