/*
 * PinkyAI.h
 *
 *  Created on: Mar 26, 2018
 *      Author: Astrid
 */

#ifndef GAME_AI_PINKYAI_H_
#define GAME_AI_PINKYAI_H_

#include "AI.h"

namespace Game
{

	class PinkyAI : public AI
	{
	private:
		Util::Location getChaseTarget(const Util::Location& loc) const noexcept override;
	public:
		PinkyAI();
		PinkyAI(const PinkyAI& ai);
		virtual ~PinkyAI();

		PinkyAI& operator=(const PinkyAI& ai);
	};

} /* namespace Game */

#endif /* GAME_AI_PINKYAI_H_ */
