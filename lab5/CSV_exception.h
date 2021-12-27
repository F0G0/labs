#pragma once

#include <exception>

#include <iostream>



class CSV_exception : public std::exception {

protected:
	std::string e_message;
	CSV_exception();
	CSV_exception(const std::string&);
public:
	virtual ~CSV_exception() = default;
	virtual const char* what() const;
};



class CSV_stream_exception : public CSV_exception {

public:
	CSV_stream_exception(const std::string&);
};



class CSV_parse_exception : public CSV_exception {

public:
	CSV_parse_exception(size_t, size_t);
};



class CSV_config_exception : public CSV_exception {
public:
	CSV_config_exception(const std::string&);
};

