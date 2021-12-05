#pragma once

class FileDoesNotExist : public std::exception {
    std::string exception;
public:
    FileDoesNotExist(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};
