/*
 * GameInfo.cpp
 *
 *  Created on: Apr 6, 2018
 *      Author: Astrid
 */

#include "GameInfo.h"

namespace Game
{

	GameInfo::GameInfo()
	{
		this->lives = DEFAULT_LIVES;
		this->score = 0;
		this->gameState = NOT_STARTED;
	}

	GameInfo::GameInfo(const GameInfo& gi)
	{
		this->lives = gi.lives;
		this->score = gi.score;
		this->gameState = gi.gameState;
	}

	GameInfo::GameInfo(int score, int lives, GameState gameState)
	{
		this->lives = lives;
		this->score = score;
		this->gameState = gameState;
	}

	GameInfo::~GameInfo()
	{
	}

	const int GameInfo::getScore() noexcept
	{
		return this->score;
	}

	void GameInfo::setScore(int score) noexcept
	{
		this->score = score;
	}

	void GameInfo::addScore(int score) noexcept
	{
		this->score += score;
	}

	const int GameInfo::getLives() noexcept
	{
		return this->lives;
	}

	void GameInfo::setLives(int lives) noexcept
	{
		this->lives = lives;
	}

	void GameInfo::decreaseLives() noexcept
	{
		this->lives--;
		if(this->lives <= 0)
		{
			this->gameState = GAME_OVER;
		}
	}

	const GameState GameInfo::getGameState() noexcept
	{
		return this->gameState;
	}

	void GameInfo::setGameState(GameState gameState) noexcept
	{
		this->gameState = gameState;
	}

	void GameInfo::togglePause() noexcept
	{
		if(this->gameState == PAUSED)
		{
			this->gameState = RUNNING;
		}
		else if(this->gameState == RUNNING)
		{
			this->gameState = PAUSED;
		}
	}

} /* namespace Game */
