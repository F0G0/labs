#include "CSV_iterator_exception.h"



CSV_iterator_exception::CSV_iterator_exception(const std::string& str) : e_message(str)
{
}



CSV_iterator_exception::CSV_iterator_exception() : e_message("you broke something")
{
}



const char* CSV_iterator_exception::what() const
{
	return e_message.c_str();
}



CSV_out_of_range_exception::CSV_out_of_range_exception(const std::string& str) : CSV_iterator_exception(str)
{
}