/*
 * ClydeAI.h
 *
 *  Created on: Mar 26, 2018
 *      Author: Astrid
 */

#ifndef GAME_AI_CLYDEAI_H_
#define GAME_AI_CLYDEAI_H_

#include "AI.h"

namespace Game
{

class ClydeAI: public AI
{
public:
	ClydeAI();
	ClydeAI(const ClydeAI& ai);
	virtual ~ClydeAI();

	ClydeAI& operator=(const ClydeAI& ai);
};

} /* namespace Game */

#endif /* GAME_AI_CLYDEAI_H_ */
