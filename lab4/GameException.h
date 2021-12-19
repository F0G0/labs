#pragma once
#include <string>
#include <stdexcept>
class GameException : public std::runtime_error
{
public:
    GameException(const std::string& m) : std::runtime_error(m) {}
};
