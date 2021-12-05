#include <stdexcept>
#include <fstream>
#include "WriteFile.h"
#include "BlockMaker.h"

static BlockMaker<WriteFile> maker("writefile");

std::list<std::string>& WriteFile::Execute(const std::list<std::string> &parameters, std::list<std::string>& text) {
    if (parameters.size() != 1) {throw IncorrectAmountOfParams("Write needs only one param. "
                                                           + std::to_string(parameters.size()));}
    std::string filename = parameters.back();
    std::ofstream file;
    try {
        file.open(filename, std::ios::out);
    } catch (std::exception& exception) {
        throw FileDoesNotExist("file " + filename + "doesnt exist");
    }

    for (auto it = text.begin(); it != text.end(); ++it) {
        file << *it << std::endl;
    }
    file.close();
    return text;
}