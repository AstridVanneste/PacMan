/*
 * Config.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: Astrid
 */

#include "Config.h"
#include <iostream>
#include <fstream>
#include <algorithm>

namespace Settings
{

	Config::Config()
	{
	}


	Config::~Config()
	{
	}

	Config& Config::getInstance()
	{
		static Config instance;
		return instance;
	}

	void Config::setPath(const string& fname) noexcept
	{
		this->fname = fname;
		this->extractKeys();
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
	}

	const void Config::extractValue(string& value, const size_t& sepPos, const string& line) noexcept
	{
		value = line.substr(sepPos + 1);
	}

	const void Config::extractContents(const string& line) noexcept
	{
		string temp = line;

		temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());


		size_t sepPos = temp.find('=');

		string key, value;
		extractKey(key, sepPos, temp);
		extractValue(value, sepPos, temp);

		if(!keyExists(key))
		{
			contents.insert(pair<string,string>(key, value));
		}
		else
		{
			cout << "CFG: Can only have unique key names!\n" << endl;
		}
	}

	void Config::parseLine(const string& line, const size_t lineNo)
	{
		if(line.find('=') == line.npos)
		{
			cout << "CFG: Couldn't find seperator on line " << lineNo << endl;
		}
		else
		{
			if(!validLine(line))
			{
				cout << "CFG: Bad format for line " << lineNo << endl;
			}
			else
			{
				extractContents(line);
			}
		}
	}

	void Config::extractKeys()
	{

		ifstream file;
		file.open(this->fname);

		if(!file)
		{
			cout << "CFG: File " << this->fname << " couldn't be found!" << endl;
		}
		else
		{
			string line;
			size_t lineNo = 0;
			while(std::getline(file, line))
			{
				lineNo++;
				string temp = line;
				if(temp.empty())
				{
					continue;
				}
				this->removeComment(temp);

				if(this->onlyWhiteSpace(temp))
				{
					continue;
				}

				parseLine(temp, lineNo);
			}
		}

		file.close();
	}

	const bool Config::keyExists(const string& key) noexcept
	{
		bool result = contents.find(key) != contents.end();
		//cout << "keyExists(" << key << ") = " << result << endl;
		return result;
	}


} /* namespace Settings */
