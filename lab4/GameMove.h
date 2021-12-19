#pragma once
#include <string>

class GameMove {
public:
    virtual ~GameMove() {}

    virtual GameMove& operator=(const std::string&) = 0;

    virtual operator std::string() const = 0;

    virtual bool Equals(const GameMove& other) const = 0;

    friend bool operator==(const GameMove& lhs, const GameMove& rhs) {
        return lhs.Equals(rhs);
    }
};