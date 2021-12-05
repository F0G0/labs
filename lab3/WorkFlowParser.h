#pragma once

#include "BlockArguments.h"
#include <map>


class WorkFlowParser {

    std::map<int, BlockArguments> map_of_block_arguments;
    std::list<int> scheme;
public:
    void ReadFlowFile(std::string file);

    const std::map<int, BlockArguments> &GetBlockArguments() const;

    const std::list<int> &GetScheme() const;


private:
    void BlocksFromString(std::string& line);
    void SchemeFromString(std::string& line);
};
