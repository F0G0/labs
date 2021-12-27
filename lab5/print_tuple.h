#pragma once

#include <iostream>

#include <tuple>



template<class Ch, class Tr, class... argType>
auto& operator<<(std::basic_ostream<Ch, Tr>& os, std::tuple<argType...> const& t) {
	std::apply([&os](auto&&...args) {((os << "<" << args << "> "), ...); }, t);
	return os;
};


