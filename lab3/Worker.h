#pragma once

#include <string>
#include <list>
#include "IncorrectAmountOfParams.h"
#include "FileDoesNotExist.h"
#include "UnavailableWorkFlow.h"
#include "CantOpenFile.h"


enum class StreamType{
    NO_TYPE,
    TEXT
};


class Worker{
public:
    virtual std::list<std::string>& Execute(const std::list<std::string>& parameters, std::list<std::string>& text) = 0;
    virtual StreamType& GetOutType(StreamType& out_type) = 0;
    virtual StreamType& GetInType(StreamType& in_type) = 0;
    virtual ~Worker() = default;
};
