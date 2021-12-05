#include <stdexcept>
#include "BlockFactory.h"
#include "TooManyMakersForOneKey.h"
#include "UnrecognizedKey.h"


BlockFactory& BlockFactory::Instance() {
    static BlockFactory factory;
    return factory;
}

void BlockFactory::RegisterMaker(const std::string &key, IBlockMaker *maker) {
    if (makers.find(key) != makers.end())
    {
        throw TooManyMakerForOneKey("Too many makers.");
    }
    makers[key] = maker;
}

Worker* BlockFactory::create(const std::string &key) {
    auto i = makers.find(key);
    if (i == makers.end())
    {
        throw UnrecognizedKey(key + " is unrecognized.");
    }
    IBlockMaker* maker = i->second;
    return maker->create();
}



