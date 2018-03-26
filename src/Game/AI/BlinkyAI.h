/*
 * BlinkyAI.h
 *
 *  Created on: Mar 26, 2018
 *      Author: Astrid
 */

#ifndef GAME_AI_BLINKYAI_H_
#define GAME_AI_BLINKYAI_H_

#include "AI.h"

namespace Game
{

	class BlinkyAI: public AI
	{
	public:
		BlinkyAI();
		BlinkyAI(const BlinkyAI& ai);
		virtual ~BlinkyAI();

		BlinkyAI& operator=(const BlinkyAI& ai);
	};

} /* namespace SDL */

#endif /* GAME_AI_BLINKYAI_H_ */
