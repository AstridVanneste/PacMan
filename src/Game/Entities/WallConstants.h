//Constants used to compose index for WALL_IMAGE matrix.
enum NEIGHBOUR_WALLS
{
	WALL_LEFT = 1,
	WALL_UP = 1<<1,
	WALL_RIGHT = 1<<2,
	WALL_DOWN = 1<<3
};

//Constants that can be used as index for WALL_IMAGE matrix.
//Composed using the NEIGHBOUR_WALLS enum.
const char UNDEFINED_WALL = 0;
const char EMPTY_WALL = 16;

const char L = WALL_LEFT;											//0001		1
const char U = WALL_UP;												//0010		2
const char R = WALL_RIGHT;											//0100		4
const char D = WALL_DOWN;											//1000		8

const char LU = WALL_LEFT | WALL_UP;								//0011		3
const char LR = WALL_LEFT | WALL_RIGHT;								//0101		5
const char LD = WALL_LEFT | WALL_DOWN;								//1001		9
const char UR = WALL_UP | WALL_RIGHT;								//0110		6
const char UD = WALL_UP | WALL_DOWN;								//1010		10
const char RD = WALL_RIGHT | WALL_DOWN;								//1100		12

const char LUR  = WALL_LEFT | WALL_UP | WALL_RIGHT;					//0111		7
const char LUD = WALL_LEFT | WALL_UP | WALL_DOWN;					//1011		11
const char LRD = WALL_LEFT | WALL_RIGHT | WALL_DOWN;				//1101		13
const char URD = WALL_UP | WALL_RIGHT | WALL_DOWN;					//1110		14

const char LURD = WALL_LEFT | WALL_UP | WALL_RIGHT | WALL_DOWN;		//1111		15

const char DOT_WALL = 16;

const int  WALL_IMAGE[17][2] =					//[i][0] -> x coordinate in picture	(top = 0)
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
		{4,1}	//16
};

const int DEFAULT_DOT_VALUE = 100;
