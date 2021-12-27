#pragma once

#include <iostream>

#include <sstream>

#include "CSV_exception.h"

#include "CSV_iterator_exception.h"



template<class T>
bool convert(T& value, const std::string& str, size_t& start, char divider);



template<class TupleType, size_t... I>
int parse(TupleType& result, std::index_sequence<I...>, const std::string& str, char divider);



template<class... argType>
class CSV_parser
{

private:

	std::istream& stream;

	char divider;

	size_t size;

	std::tuple<argType...> getLine(size_t, size_t&, bool&, size_t);

public:

	CSV_parser(std::ifstream&, char = ',');

	class CSV_iterator {

		friend class CSV_parser<argType...>;

	private:

		size_t position;

		size_t nextPosition;

		bool end;

		std::tuple<argType...> line;

		size_t number;

		CSV_parser* csvp;

		CSV_iterator(CSV_parser*, size_t, size_t, bool);


	public:

		std::tuple<argType...> operator*() const;

		CSV_iterator& operator++();

		CSV_iterator& operator++(int);

		friend bool operator==
			(const CSV_parser<argType...>::CSV_iterator& a,
				const CSV_parser<argType...>::CSV_iterator& b)
		{
			if (a.csvp != b.csvp || a.end != b.end) return false;
			else if (a.end)
				return true;
			return (a.position == b.position);
		}
		
		friend bool operator!=
			(const CSV_parser<argType...>::CSV_iterator& a,
				const CSV_parser<argType...>::CSV_iterator& b)
		{
			return !(a == b);
		}

	};

	CSV_iterator begin();

	CSV_iterator end();
	
};



template<class... argType>
CSV_parser<argType...>::CSV_iterator::CSV_iterator
(CSV_parser* csvp, size_t position, size_t number, bool end)
	: csvp(csvp), position(position), nextPosition(position), number(number), end(end)
{
	if (end)
		return;
	line = csvp->getLine(position, nextPosition, end, number);
}



template<class... argType>
std::tuple<argType...> CSV_parser<argType...>::CSV_iterator::operator*() const
{

	if (end)
		throw CSV_out_of_range_exception("Cannot dereference end iterator");
	return line;

}



template<class... argType>
typename CSV_parser<argType...>::CSV_iterator&
CSV_parser<argType...>::CSV_iterator::operator++()
{

	if (end)
		throw CSV_out_of_range_exception("Cannot increment end iterator");
	if (position == nextPosition) {
		end = true;
		return *this;
	}
	position = nextPosition;
	++number;
	line = csvp->getLine(position, nextPosition, end, number);
	return *this;

}



template<class... argType>
typename CSV_parser<argType...>::CSV_iterator& CSV_parser<argType...>::CSV_iterator::operator++(int)
{

	auto t = std::copy(*this);
	++(*this);
	return t;

}


template<class... argType>
CSV_parser<argType...>::CSV_parser(std::ifstream& is, char divider)
	:divider(divider), stream(is)
{

	if (!stream)
		throw CSV_stream_exception("stream is not opened");
	if (divider == '\\')
		throw CSV_config_exception("\"\\\" character is reserved");

	auto prev = stream.tellg();
	stream.seekg(0, SEEK_END);
	size = stream.tellg();
	stream.seekg(prev, SEEK_SET);

}



template<class... argType>
typename CSV_parser<argType...>::CSV_iterator CSV_parser<argType...>::begin()
{
	return CSV_iterator(this, 0, 0, false);

}



template<class... argType>
typename CSV_parser<argType...>::CSV_iterator CSV_parser<argType...>::end()
{

	return CSV_iterator(this, size, 0, true);

}



template<class... argType>
std::tuple<argType...> CSV_parser<argType...>::getLine(size_t start, size_t& next, bool& end, size_t n) {

	std::tuple<argType...> result;

	if (!stream)
		throw CSV_stream_exception("stream is not opened");

	size_t originalPosition = stream.tellg();
	stream.seekg(start, SEEK_SET);

	std::string str;
	std::getline(stream, str);
	if (stream.eof())
		next = start;
	else
		next = stream.tellg();
	stream.seekg(originalPosition, SEEK_SET);
	if (str == "") {
		end = true;
		return result;
	}
	int success = parse(result, std::make_index_sequence<sizeof...(argType)>{}, str, divider);
	if (success == sizeof...(argType))
		return result;
	throw CSV_parse_exception(n, success);

}



template<class T>
bool convert(T& value, const std::string& str, size_t& start, char divider) {

	std::string buffer;
	size_t position = 0;
	bool sequence = false;
	char c;

	while (true) {
		if (str.length() <= start + position) {
			std::stringstream stream(buffer);
			stream >> value;
			start = start + position;
			if (stream.fail())
				return false;
			else
				return true;
		}
		c = str[start + position];
		if (sequence)
			sequence = false;
		else if (c == '\\') {
			sequence = true;
			++position;
			continue;
		}
		else if (c == divider) {
			std::stringstream stream(buffer);
			stream >> value;
			if (stream.fail())
				return false;
			else
				break;
		}
		buffer += c;
		++position;
	}
	start = start + position + 1;
	return true;

}



template<class TupleType, size_t... I>
int parse(TupleType& result, std::index_sequence<I...>, const std::string& str, char divider) {

	size_t position = 0;

	bool success[] = { convert(std::get<I>(result), str, position, divider)... };
	for (size_t i = 0; i < sizeof...(I); ++i) {
		if (!success[i])
			return i;
	}
	return sizeof...(I);

}

