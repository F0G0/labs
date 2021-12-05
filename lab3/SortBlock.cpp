#include <stdexcept>
#include "SortBlock.h"

#include "BlockMaker.h"

static BlockMaker<SortBlock> maker("sort");

std::list<std::string>& SortBlock::Execute(const std::list<std::string> &parameters, std::list<std::string>& text) {
    if (!parameters.empty()) {
        throw IncorrectAmountOfParams("Sort doesnt need parameters. " + std::to_string(parameters.size()));
    }

    text.sort();
    return text;
}

