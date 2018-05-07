/*
 * Random.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: Astrid
 */

#include "Random.h"
using namespace std;

namespace Util
{

Random::Random()
{
	random_device rseed;
	this->generator = mt19937(rseed()); // mersenne_twister
}

Random::~Random()
{
}

Random& Random::getInstance()
{
	static Random instance;
	return instance;
}

int Random::generateRandom(int limit) const noexcept
{
	uniform_int_distribution<int> idist(0,limit); // [0,limit]
	return idist(this->generator);
}

} /* namespace Game */
