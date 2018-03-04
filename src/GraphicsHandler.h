/*
 * GraphicsHandler.h
 *
 *  Created on: Mar 1, 2018
 *      Author: Astrid
 */

#ifndef GRAPHICSHANDLER_H_
#define GRAPHICSHANDLER_H_

namespace Game
{
	class Graphics_Handler
	{
	public:
		Graphics_Handler();
		virtual ~Graphics_Handler();

		virtual bool init()=0;
		virtual bool visualizeAll()=0;
		virtual bool visualizeMap()=0;
		virtual bool visualizeComponent()=0;
	};
}

#endif /* GRAPHICSHANDLER_H_ */
