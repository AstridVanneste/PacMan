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
		this->dotsLeft = 0;
	}

	GameInfo::GameInfo(const GameInfo& gi)
	{
		this->lives = gi.lives;
		this->score = gi.score;
		this->gameState = gi.gameState;
		this->dotsLeft = gi.dotsLeft;
	}

	GameInfo::GameInfo(int score, int lives, GameState gameState)
	{
		this->lives = lives;
		this->score = score;
		this->gameState = gameState;
		this->dotsLeft = 0;
	}

	GameInfo::~GameInfo()
	{
	}

	GameInfo& GameInfo::operator =(const GameInfo& gi)
	{
		if(this != &gi)
		{
			this->lives = gi.lives;
			this->score = gi.score;
			this->gameState = gi.gameState;
			this->dotsLeft = gi.dotsLeft;
		}

		return *this;
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
		switch(this->gameState)
		{
		case PAUSED:
			this->gameState = RUNNING;
			break;
		case RUNNING:
			this->gameState = PAUSED;
			break;
		default:
			break;
		}
	}

	void GameInfo::setDotsLeft(int dotsLeft) noexcept
	{
		this->dotsLeft = dotsLeft;
	}

	void GameInfo::decreaseDotsLeft() noexcept
	{
		this->dotsLeft--;
		if(dotsLeft <= 0)
		{
			this->gameState = VICTORY;
		}
	}

} /* namespace Game */
