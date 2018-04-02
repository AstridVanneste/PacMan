/*
 * Config.h
 *
 *  Created on: Mar 28, 2018
 *      Author: Astrid
 */

#ifndef SETTINGS_CONFIG_H_
#define SETTINGS_CONFIG_H_

// Based on: http://www.dreamincode.net/forums/topic/183191-create-a-simple-configuration-file-parser/

#include <map>
#include <string>
#include "Convert.h"
#include "Keys.h"
using namespace std;

namespace Settings
{

class Config
{
private:
	map<string, string> contents;
	string fname;

	Config();

	const void removeComment(string& line) noexcept;
	const bool onlyWhiteSpace(const string& line) noexcept;
	const bool validLine(const string& line) noexcept;
	const void extractKey(string& key, const size_t& sepPos, const string& line) noexcept;
	const void extractValue(string& value, const size_t& sepPos, const string& line) noexcept;
	void extractKeys();
	const void extractContents(const string& line) noexcept;
	void parseLine(const string& line, const size_t lineNo);
public:
	virtual ~Config();

	static Config& getInstance();

	void setPath(const string& fname) noexcept;

	const bool keyExists(const string& key) noexcept;

	template <typename T> T getValueOfKey(const string& key, const T& defaultValue = T())
	{
		if(!this->keyExists(key))
		{
			return defaultValue;
		}

		//cout << "Returning " << contents.find(key)->second << endl;
		return Convert::string_to_T<T>(contents.find(key)->second);
	}
};

} /* namespace Settings */

#endif /* SETTINGS_CONFIG_H_ */
