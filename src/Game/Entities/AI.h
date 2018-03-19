/*
 * AI.h
 *
 *  Created on: 18 mrt. 2018
 *      Author: Astrid
 */

#ifndef GAME_ENTITIES_AI_H_
#define GAME_ENTITIES_AI_H_

#include "../Util/Util.h"
#include "../Arena.h"

namespace Game
{
	enum AImode{CHASE, SCATTER, FRIGHTENED};
	class AI
	{
	private:
		AImode mode;

		const Location getScatterTarget(shared_ptr<Arena> arena) noexcept;
		const Location getChaseTarget(shared_ptr<Arena> arena) noexcept;
		const Location getFrightenedTarget(shared_ptr<Arena> arena) noexcept;
	public:
		AI();
		AI(const AI& ai);
		AI& operator=(const AI& ai);
		virtual ~AI();

		const AImode getMode() noexcept;
		void setMode(const AImode& mode) noexcept;

		const Direction getNewDirection(shared_ptr<Arena> arena) noexcept;
	};
} /* namespace Game */

#endif /* GAME_ENTITIES_AI_H_ */
