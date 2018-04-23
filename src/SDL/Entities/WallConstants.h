/*
 * WallConstants.h
 *
 *  Created on: Apr 6, 2018
 *      Author: Astrid
 */

#ifndef SDL_ENTITIES_WALLCONSTANTS_H_
#define SDL_ENTITIES_WALLCONSTANTS_H_


namespace SDL
{
	const int  WALL_IMAGE[19][2] =						//[i][0] -> x coordinate in picture	(top = 0)
														//[i][1] -> y coordinate in picture (left = 0)
		{
				{3,3},	//0
				{0,3},	//1
				{0,0},	//2
				{1,0},	//3
				{0,1},	//4
				{2,1},	//5
				{1,1},	//6
				{3,1},	//7
				{0,2},	//8
				{1,2},	//9
				{2,0},	//10
				{3,0},	//11
				{1,3},	//12
				{2,3},	//13
				{3,2},	//14
				{2,2},	//15
				{4,1},	//16
				{4,1},	//17
				{4,3}	//18
		};
	}


#endif /* SDL_ENTITIES_WALLCONSTANTS_H_ */
