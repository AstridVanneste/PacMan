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
#include "AI.h"
using namespace std;

//FOR A*
//https://gamedev.stackexchange.com/questions/15/how-does-a-pathfinding-work


namespace Game
{
	enum GhostType{INKY, CLYDE, BLINKY, PINKY};

	class Ghost: public MovingEntity
	{
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
		const GhostType getType() noexcept;
		void setType(GhostType type) noexcept;
	};
}

#endif /* GHOST_H_ */
