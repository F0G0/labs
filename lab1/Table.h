#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include <ctype.h>
#include <algorithm>

class Table
{
private:
		int count;
		std::map<std::string, int> not_sorted_words;
public:
		bool IsLegal(char c) const
		{
			return (isalpha(c)||isdigit(c));
		}
	

		void ReadFile(std::string f_name);
		void PrintFile(std::string o_name);
};

