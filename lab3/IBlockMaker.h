#pragma once

class IBlockMaker {

public:
    virtual Worker* create() = 0;
    virtual ~IBlockMaker() {}
};

