/*
 * PhaseControl.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: Astrid
 */

#include "../Control/Gamemanager.h"
#include "../Control/GraphicsHandler.h"
#include "../../Settings/Config.h"
#include "ModeControl.h"

namespace Game
{

	ModeControl::ModeControl()
	{
		this->mode = SCATTER;
		this->phaseStartTime = Gamemanager::getInstance().getFactory()->getGraphicsHandler().getTime();
	}

	ModeControl::ModeControl(const ModeControl& mc)
	{
		this->mode = mc.mode;
		this->phaseStartTime = mc.phaseStartTime;
	}

	ModeControl::~ModeControl()
	{
	}

	ModeControl& ModeControl::operator=(const ModeControl& mc)
	{
		if(this != &mc)
		{
			this->mode = mc.mode;
			this->phaseStartTime = mc.phaseStartTime;
		}

		return *this;
	}

	AImode ModeControl::getMode() noexcept
	{
		if(this->modeFinished())
		{
			this->mode = this->toggleMode();
		}

		//cout << "MODE = " << this->mode << endl;

		return this->mode;
	}

	void ModeControl::setMode(const AImode& mode) noexcept
	{
		this->mode = mode;
		this->phaseStartTime = Gamemanager::getInstance().getFactory()->getGraphicsHandler().getTime();
	}

	const bool ModeControl::modeFinished() noexcept
	{
		unsigned int timeLimit = this->getTimeLimit();

		unsigned int currentT = Gamemanager::getInstance().getFactory()->getGraphicsHandler().getTime();

		unsigned int deltaT = currentT - this->phaseStartTime;
		deltaT /= 1000;

		if(deltaT >= timeLimit)
		{
			return true;
		}

		return false;
	}

	const unsigned int ModeControl::getTimeLimit() noexcept
	{

		unsigned int timeLimit;

		switch (this->mode)
		{
		case CHASE:
			timeLimit = Settings::Config::getInstance().getValueOfKey<unsigned int>(Settings::CHASE_TIME);
			break;
		case SCATTER:
			timeLimit = Settings::Config::getInstance().getValueOfKey<unsigned int>(Settings::SCATTER_TIME);
			break;
		case FLEE:
			timeLimit = Settings::Config::getInstance().getValueOfKey<unsigned int>(Settings::FLEE_TIME);
			break;
		}

		return timeLimit;
	}

	const AImode ModeControl::toggleMode() noexcept
	{
		this->phaseStartTime = Gamemanager::getInstance().getFactory()->getGraphicsHandler().getTime();

		switch(this->mode)
		{
		case CHASE:
			this->mode = SCATTER;
			break;
		case SCATTER:
			this->mode = CHASE;
			break;
		case FLEE:
			this->mode = CHASE;
			break;
		}

		return this->mode;
	}



} /* namespace Game */
