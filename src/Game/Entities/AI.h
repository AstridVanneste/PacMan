/*
 * AI.h
 *
 *  Created on: 18 mrt. 2018
 *      Author: Astrid
 */

#ifndef GAME_ENTITIES_AI_H_
#define GAME_ENTITIES_AI_H_

#include "../Util/Direction.h"
#include "../Util/Location.h"

namespace Game
{
	enum AImode{CHASE, SCATTER, FRIGHTENED};
	class AI
	{
	private:
		AImode mode;

		const Util::Location getScatterTarget() noexcept;
		const Util::Location getChaseTarget() noexcept;
		const Util::Location getFrightenedTarget() noexcept;

		const int getDistance(const Util::Location& loc, const Util::Location& target) noexcept;
		const Direction getOptimalDirection(const Util::Location& loc, const Util::Location& target, Direction direction) noexcept;
	public:
		AI();
		AI(const AI& ai);
		AI& operator=(const AI& ai);
		virtual ~AI();

		const AImode getMode() noexcept;
		void setMode(const AImode& mode) noexcept;

		const Direction getNewDirection(const Util::Location& loc, Direction direction) noexcept;
	};
} /* namespace Game */

#endif /* GAME_ENTITIES_AI_H_ */
