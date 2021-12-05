#pragma once

class UnavailableWorkFlow : public std::exception {
    std::string exception;
public:
    UnavailableWorkFlow(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};
