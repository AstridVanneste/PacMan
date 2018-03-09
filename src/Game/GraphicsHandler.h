/*
 * GraphicsHandler.h
 *
 *  Created on: Mar 1, 2018
 *      Author: Astrid
 */

#ifndef GRAPHICSHANDLER_H_
#define GRAPHICSHANDLER_H_

#include "Map.h"

namespace Game
{
	class Graphics_Handler
	{
	public:
		Graphics_Handler();
		virtual ~Graphics_Handler();

		static Graphics_Handler& getInstance();

		virtual bool init(Location location)=0;
		virtual void delay(int time)=0;
		virtual unsigned int getTime()=0;
		virtual bool visualizeAll(shared_ptr<Map> map)=0;
		virtual bool visualizeMap()=0;
		virtual bool visualizeComponent()=0;
	};
}

#endif /* GRAPHICSHANDLER_H_ */
