#pragma once

class TooManyMakerForOneKey : public std::exception {
    std::string exception;
public:
    TooManyMakerForOneKey(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};


