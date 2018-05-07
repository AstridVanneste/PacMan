/*
 * InkyAI.h
 *
 *  Created on: Mar 26, 2018
 *      Author: Astrid
 */

#ifndef GAME_AI_INKYAI_H_
#define GAME_AI_INKYAI_H_

#include "AI.h"

namespace Game
{

class InkyAI: public AI
{
private:
		Util::Location getChaseTarget(const Util::Location& loc) const noexcept override;
public:
	InkyAI();
	InkyAI(const InkyAI& ai);
	virtual ~InkyAI();

	InkyAI& operator=(const InkyAI& ai);
};

} /* namespace Game */

#endif /* GAME_AI_INKYAI_H_ */
