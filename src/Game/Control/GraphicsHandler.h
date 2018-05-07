/*
 * GraphicsHandler.h
 *
 *  Created on: Mar 1, 2018
 *      Author: Astrid
 */

#ifndef GRAPHICSHANDLER_H_
#define GRAPHICSHANDLER_H_

#include "Arena.h"

namespace Game
{
	class GraphicsHandler
	{
	public:
		GraphicsHandler();
		virtual ~GraphicsHandler();

		static GraphicsHandler& getInstance();

		virtual bool init(Util::Location location)=0;
		virtual void delay(int time)=0;
		virtual unsigned int getTime()=0;
		const virtual bool visualizeAll()=0;

		const virtual bool playMusic()=0;
	};
}

#endif /* GRAPHICSHANDLER_H_ */
