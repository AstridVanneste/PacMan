/*
 * Convert.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: Astrid
 */

#include "Convert.h"


namespace Settings
{
	Convert::Convert()
	{
	}

	Convert::~Convert()
	{
	}

	void Convert::exitWithError(const string& error)
	{
		cout << error;
		cin.ignore();
		cin.get();

		exit(EXIT_FAILURE);
	}

} /* namespace Settings */
