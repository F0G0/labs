#pragma once

#include "Worker.h"
#include "IBlockMaker.h"
#include <map>

class BlockFactory{
public:
    static BlockFactory& Instance();
    Worker* create(const std::string &key);
    void RegisterMaker(const std::string& key, IBlockMaker* maker);

private:

    std::map<std::string, IBlockMaker*> makers;

};

