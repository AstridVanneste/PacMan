/*
 * Map.h
 *
 *  Created on: 4 mrt. 2018
 *      Author: Astrid
 */

#ifndef GAME_ARENA_H_
#define GAME_ARENA_H_
#include "Entities/Entity.h"
#include "Entities/MovingEntity.h"
#include "Entities/Pacman.h"
#include "Entities/Wall.h"
#include "Entities/Ghost.h"
#include <string>
#include <vector>
#include <memory>
using namespace std;

namespace Game
{

	/*
	 * 	[ axy	a12		a13		a14	]
	 * 	[ a21	a22		a23		a24 ]
	 * 	[ a31	a32		a33		a34 ]
	 * 	[ a41	a42		a43		a44 ]
	 *
	 *	x = row
	 *	y = column
	 */
	class Arena
	{
	private:
		shared_ptr<Pacman> pacman;
		vector<vector<shared_ptr<Wall>>> arena;
		vector<shared_ptr<Ghost>> ghosts;

		void setWallTypes();
	public:
		Arena();
		Arena(const Arena& a);
		virtual ~Arena();

		Arena& operator=(const Arena& a);

		void setWall(const Util::Location& location, shared_ptr<Wall> wall) noexcept;
		const shared_ptr<Wall> getWall(const Util::Location& location) noexcept;
		bool loadFromFile(string path);

		const unsigned int getSizeX() noexcept;
		const unsigned int getSizeY() noexcept;
		const Util::Location getSize() noexcept;

		const shared_ptr<Ghost> getGhost(int i) noexcept;
		const int numberGhosts() noexcept;
		void moveGhost(int i, Util::Location destination) noexcept;

		const shared_ptr<Pacman> getPacman() noexcept;
		void movePacman(Util::Location destination) noexcept;

		const shared_ptr<vector<Direction>> getPosDir(const Util::Location& loc) noexcept;


		void visualize();
	};

} /* namespace Game */

#endif /* GAME_ARENA_H_ */
