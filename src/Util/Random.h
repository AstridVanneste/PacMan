/*
 * Random.h
 *
 *  Created on: Mar 12, 2018
 *      Author: Astrid
 */

#ifndef GAME_UTIL_RANDOM_H_
#define GAME_UTIL_RANDOM_H_
#include <random>
using namespace std;

namespace Util
{

class Random
{
private:
	mt19937 generator;
	Random();
public:
	virtual ~Random();

	static Random& getInstance();

	int generateRandom(int limit) const noexcept;
};

} /* namespace Game */

#endif /* GAME_UTIL_RANDOM_H_ */
