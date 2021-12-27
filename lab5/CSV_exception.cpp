#include "CSV_exception.h"

#include <string>

#include <iostream>



CSV_exception::CSV_exception(const std::string& str) : e_message(str)
{
}



CSV_exception::CSV_exception() : e_message("you broke something")
{
}



const char* CSV_exception::what() const
{
	return e_message.c_str();
}



CSV_stream_exception::CSV_stream_exception(const std::string& str) : CSV_exception(str)
{
}



CSV_parse_exception::CSV_parse_exception(size_t line, size_t column)
{
	e_message = "parsing error at [" + std::to_string(line) + "][" + std::to_string(column) + "]";
}



CSV_config_exception::CSV_config_exception(const std::string& str) : CSV_exception(str)
{
}