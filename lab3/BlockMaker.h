#pragma once

#include "IBlockMaker.h"
#include "BlockFactory.h"

template<typename T>
class BlockMaker : public IBlockMaker
{
public:
    Worker* create() override{
        return new T();
    }

    BlockMaker(const std::string& key)
    {
        BlockFactory::Instance().RegisterMaker(key, this);
    }
};

