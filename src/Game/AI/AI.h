/*
 * AI.h
 *
 *  Created on: 18 mrt. 2018
 *      Author: Astrid
 */

#ifndef GAME_ENTITIES_AI_H_
#define GAME_ENTITIES_AI_H_

#include <memory>
#include "../../Util/Direction.h"
#include "../../Util/Location.h"
#include "ModeControl.h"

namespace Game
{

	class AI
	{
	private:
		shared_ptr<ModeControl> modeControl;

		const virtual Util::Location getChaseTarget(const Util::Location& loc) noexcept =0;
		const Util::Location getFrightenedTarget() noexcept;

		const Util::Direction getOptimalDirection(const Util::Location& loc, const Util::Location& target, Util::Direction direction) noexcept;
	protected:
		Util::Location scatterTarget;
		const int getDistance(const Util::Location& loc, const Util::Location& target) noexcept;
	public:
		AI();
		AI(const AI& ai);
		AI& operator=(const AI& ai);
		virtual ~AI();

		const AImode getMode() noexcept;
		void setMode(const AImode& mode) noexcept;

		const Util::Direction getNewDirection(const Util::Location& loc, Util::Direction direction) noexcept;
	};
} /* namespace Game */

#endif /* GAME_ENTITIES_AI_H_ */
