/*
 * Convert.h
 *
 *  Created on: Mar 28, 2018
 *      Author: Astrid
 */

#ifndef SETTINGS_CONVERT_H_
#define SETTINGS_CONVERT_H_

// Based on: http://www.dreamincode.net/forums/topic/183191-create-a-simple-configuration-file-parser/

#include <string>
#include <iostream>
#include <sstream>
#include <typeinfo>
using namespace std;

namespace Settings
{

class Convert
{
public:
	Convert();
	virtual ~Convert();

	template<typename T> static string T_to_string(const T& val)
	{
		ostringstream ostr;
		ostr << val;

		return ostr.str();
	}

	template<typename T> static T string_to_T(const string& val)
	{
		istringstream istr(val);
		T returnVal;

		if(!(istr >> returnVal))
		{
			exitWithError("CFG: Not a valid " + (string)typeid(T).name() + " received!\n");
		}

		return returnVal;
	}

	static void exitWithError(const string& error);
};

} /* namespace Settings */

#endif /* SETTINGS_CONVERT_H_ */
