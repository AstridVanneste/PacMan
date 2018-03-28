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
using namespace std;

namespace Settings
{

class Config
{
private:
	map<string, string> contents;
	string fname;

	const void removeComment(string& line) noexcept;
	const bool onlyWhiteSpace(const string& line) noexcept;
	const bool validLine(const string& line) noexcept;
	const void extractKey(string& key, const size_t& sepPos, const string& line) noexcept;
	const void extractValue(string& value, const size_t& sepPos, const string& line) noexcept;
	void extractKeys();
	const void extractContents(const string& line) noexcept;
public:
	Config();
	Config(const string& fname);
	virtual ~Config();

	const bool keyExists(const string& key) noexcept;

	template <typename T> T getValueOfKey(const string& key, const T& defaultValue = T());
};

} /* namespace Settings */

#endif /* SETTINGS_CONFIG_H_ */
