#pragma once

#include "WorkFlowParser.h"

class WorkFlow{
    WorkFlowParser parser;
public:
    void exeWorkFlow(const std::string& filename);
};