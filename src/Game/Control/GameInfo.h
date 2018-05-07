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
	enum GameState{RUNNING, PAUSED, GAME_OVER, NOT_STARTED, VICTORY};

	const int DEFAULT_LIVES = 3;

	class GameInfo
	{
	protected:
		int score;
		int lives;
		int dotsLeft;
		GameState gameState;
	public:
		GameInfo();
		GameInfo(const GameInfo& gi);
		GameInfo(int score, int lives, GameState gameState);
		virtual ~GameInfo();

		GameInfo& operator=(const GameInfo& gi);

		void setDotsLeft(int dotsLeft) noexcept;
		void decreaseDotsLeft() noexcept;

		int getScore() const noexcept;
		void setScore(int score) noexcept;
		void addScore(int score) noexcept;

		int getLives() const noexcept;
		void setLives(int lives) noexcept;
		void decreaseLives() noexcept;

		GameState getGameState() const noexcept;
		void setGameState(GameState gameState) noexcept;
		void togglePause() noexcept;

		virtual void visualize() const =0;
	};

} /* namespace Game */

#endif /* GAME_CONTROL_GAMEINFO_H_ */
