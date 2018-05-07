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

		virtual Util::Location getChaseTarget(const Util::Location& loc) const noexcept =0;
		Util::Location getFrightenedTarget() const noexcept;

		Util::Direction getOptimalDirection(const Util::Location& loc, const Util::Location& target, Util::Direction direction) const noexcept;
	protected:
		Util::Location scatterTarget;
		int getDistance(const Util::Location& loc, const Util::Location& target) const noexcept;
	public:
		AI();
		AI(const AI& ai);
		AI& operator=(const AI& ai);
		virtual ~AI();

		AImode getMode() const noexcept;
		void setMode(const AImode& mode) noexcept;
		void toggleMode() noexcept;

		Util::Direction getNewDirection(const Util::Location& loc, Util::Direction direction) const noexcept;
	};
} /* namespace Game */

#endif /* GAME_ENTITIES_AI_H_ */
