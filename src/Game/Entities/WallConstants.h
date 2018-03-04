//constants used to compose index for WALL_IMAGE matrix.
enum neighbouringWalls
{
	LEFT = 1,
	UP = 1<<1,
	RIGHT = 1<<2,
	DOWN = 1<<3
};

//constants that can be used as index for WALL_IMAGE matrix.
const char L = LEFT;							//0001		1
const char U = UP;								//0010		2
const char R = RIGHT;							//0100		4
const char D = DOWN;							//1000		8

const char LU = LEFT | UP;						//0011		3
const char LR = LEFT | RIGHT;					//0101		5
const char LD = LEFT | DOWN;					//1001		9
const char UR = UP | RIGHT;						//0110		6
const char UD = UP | DOWN;						//1010		10
const char RD = RIGHT | DOWN;					//1100		12

const char LUR  = LEFT | UP | RIGHT;			//0111		7
const char LUD = LEFT | UP | DOWN;				//1011		11
const char LRD = LEFT | RIGHT | DOWN;			//1101		13
const char URD = UP | RIGHT | DOWN;				//1110		14

const char LURD = LEFT | UP | RIGHT | DOWN;		//1111		15

const int  WALL_IMAGE[15][2] =					//[i][0] -> x coordinate in picture	(left = 0)
												//[i][1] -> y coordinate in picture (top = 0)
{
		{0,3},
		{0,0},
		{1,0},
		{0,1},
		{2,1},
		{1,1},
		{3,1},
		{0,2},
		{1,2},
		{2,0},
		{0,3},
		{1,3},
		{2,3},
		{3,2},
		{2,2}
};
