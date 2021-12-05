#pragma once

class CantOpenFile : public std::exception {
    std::string exception;
public:
    CantOpenFile(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};
