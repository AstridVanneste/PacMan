/*
 * GameInfo.h
 *
 *  Created on: Apr 6, 2018
 *      Author: Astrid
 */

#ifndef GAME_CONTROL_GAMEINFO_H_
#define GAME_CONTROL_GAMEINFO_H_

namespace Game
{
	enum GameState{RUNNING, PAUSED, GAME_OVER, NOT_STARTED};

	const int DEFAULT_LIVES = 3;

	class GameInfo
	{
	protected:
		int score;
		int lives;
		GameState gameState;
	public:
		GameInfo();
		GameInfo(const GameInfo& gi);
		GameInfo(int score, int lives, GameState gameState);
		virtual ~GameInfo();

		const int getScore() noexcept;
		void setScore(int score) noexcept;
		void addScore(int score) noexcept;

		const int getLives() noexcept;
		void setLives(int lives) noexcept;
		void decreaseLives() noexcept;

		const GameState getGameState() noexcept;
		void setGameState(GameState gameState) noexcept;
		void togglePause() noexcept;

		const virtual void visualize()=0;
	};

} /* namespace Game */

#endif /* GAME_CONTROL_GAMEINFO_H_ */
