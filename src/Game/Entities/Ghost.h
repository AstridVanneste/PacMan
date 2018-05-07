/*
 * Ghost.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef GHOST_H_
#define GHOST_H_
#include <string>
#include <memory>
#include "MovingEntity.h"
#include "../AI/AI.h"
using namespace std;

//FOR A*
//https://gamedev.stackexchange.com/questions/15/how-does-a-pathfinding-work


namespace Game
{
	enum GhostType{INKY, CLYDE, BLINKY, PINKY};

	class Ghost: public MovingEntity
	{
	private:
		void createAI() noexcept;
	protected:
		GhostType type;
		unique_ptr<AI> ai;
	public:
		Ghost();
		Ghost(const Ghost& g);
		Ghost(GhostType type);
		Ghost(Util::Location location, GhostType type);

		Ghost& operator=(const Ghost& g);

		virtual ~Ghost();

		bool update() noexcept override;
		GhostType getType() const noexcept;
		void setType(GhostType type) noexcept;

		AImode getMode() const noexcept;
		void setMode(const AImode& mode) noexcept;
		void toggleMode() noexcept;

		void respawn() noexcept override;
	};
}

#endif /* GHOST_H_ */
