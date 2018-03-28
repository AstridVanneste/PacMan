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
using namespace std;

namespace Settings
{

class Convert
{
public:
	Convert();
	virtual ~Convert();

	template<typename T> static string T_to_string(const T& val);
	template<typename T> static T string_to_T(const string& val);

	static void exitWithError(const string& error);
};

} /* namespace Settings */

#endif /* SETTINGS_CONVERT_H_ */
