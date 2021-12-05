#pragma once

class UnrecognizedKey : public std::exception {
    std::string exception;
public:
    UnrecognizedKey(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};
