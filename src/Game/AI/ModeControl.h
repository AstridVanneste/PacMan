/*
 * PhaseControl.h
 *
 *  Created on: Apr 22, 2018
 *      Author: Astrid
 */

#ifndef GAME_AI_MODECONTROL_H_
#define GAME_AI_MODECONTROL_H_

namespace Game
{

	enum AImode{CHASE, SCATTER, FLEE};

	class ModeControl
	{
	private:
		AImode mode;
		unsigned int phaseStartTime;

		const bool modeFinished() noexcept;
		const unsigned int getTimeLimit() noexcept;
	public:
		ModeControl();
		ModeControl(const ModeControl& mc);
		virtual ~ModeControl();

		ModeControl& operator=(const ModeControl& mc);

		AImode getMode() noexcept;
		void setMode(const AImode& mode) noexcept;

		const AImode toggleMode() noexcept;
	};

} /* namespace Game */

#endif /* GAME_AI_MODECONTROL_H_ */
