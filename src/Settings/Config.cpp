/*
 * Config.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: Astrid
 */

#include "Config.h"
#include <iostream>

namespace Settings
{

	Config::Config()
	{
		cout << "ERROR: Config object made without filename!!" << endl;
	}

	Config::~Config()
	{
	}

	const void Config::removeComment(string& line) noexcept
	{
		if(line.find('#') != line.npos)
		{
			line.erase(line.find('#'));
		}
	}

	const bool Config::onlyWhiteSpace(const string& line) noexcept
	{
		if(line.find_first_not_of(' ') == line.npos)
		{
			return true;
		}
		return false;
	}

	const bool Config::validLine(const string& line) noexcept
	{
		string temp = line;
		temp.erase(0, temp.find_first_not_of("\t "));
		if(temp[0] == '=')
		{
			return false;
		}

		for(size_t i = temp.find('=') + 1; i < temp.length(); i++)
		{
			if(temp[i] != ' ')
			{
				return true;
			}
		}

		return false;
	}

	const void Config::extractKey(string& key, const size_t& sepPos, const string& line) noexcept
	{
		key = line.substr(0, sepPos);
		if(key.find('\t') != line.npos || key.find(' ') != line.npos)
		{
			key.erase(key.find_first_of(("\t")));
		}
	}

	const void extractValue(string& value, const size_t& sepPos, string& line)
	{

	}

} /* namespace Settings */
