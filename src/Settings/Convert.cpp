/*
 * Convert.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: Astrid
 */

#include "Convert.h"
#include <iostream>
#include <sstream>
#include <typeinfo>

namespace Settings
{
	Convert::Convert()
	{
	}

	Convert::~Convert()
	{
	}

	// Convert T, which should be primitive to a string
	template<typename T> string Convert::T_to_string(const T& val)
	{
		ostringstream ostr;
		ostr << val;

		return ostr.str();
	}

	// Convert a string to T.
	template<typename T> T Convert::string_to_T(const string& val)
	{
		istringstream istr(val);
		T returnVal;

		if(!(istr >> returnVal))
		{
			exitWithError("CFG: Not a valid " + (string)typeid(T).name() + " received!\n");
		}
	}

	void Convert::exitWithError(const string& error)
	{
		cout << error;
		cin.ignore();
		cin.get();

		exit(EXIT_FAILURE);
	}

} /* namespace Settings */
