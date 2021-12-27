#include "print_tuple.h"

#include <iostream>

#include "CSV_parser.h"

#include <fstream>




int main() {
	std::ifstream fin("in.txt");
	try
	{

		CSV_parser<int, std::string, double> csv(fin, ',');
		for (auto line : csv)
			std::cout << line << std::endl;

	}
	catch (std::exception& e)
	{

		std::cerr << e.what() << std::endl;

	}
	return 0;
}