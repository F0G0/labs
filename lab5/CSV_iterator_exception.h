#pragma once


#include <exception>

#include <iostream>



class CSV_iterator_exception : public std::exception {

protected:

	std::string e_message;

	CSV_iterator_exception(const std::string&);

	CSV_iterator_exception();

public:

	virtual ~CSV_iterator_exception() = default;

	virtual const char* what() const;

};



class CSV_out_of_range_exception : public CSV_iterator_exception {

public:

	CSV_out_of_range_exception(const std::string&);

};
