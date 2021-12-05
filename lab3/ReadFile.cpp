#include <stdexcept>
#include <fstream>
#include "ReadFile.h"
#include "BlockMaker.h"

static BlockMaker<ReadFile> maker("readfile");

std::list<std::string>& ReadFile::Execute(const std::list<std::string> &parameters,std::list<std::string> &text) {
    if (parameters.size() != 1) {throw IncorrectAmountOfParams("Read File needs only one param. "
    + std::to_string(parameters.size()));}
    std::string filename = parameters.back();

    std::ifstream file;
    try{
        file.open(filename, std::ios::in);
    } catch (std::exception& exception) {
        throw CantOpenFile("Cant open file: " + filename);
    }

    while (!file.eof()) {
        std::string line;
        std::getline(file,line);
        text.push_back(line);
    }
    file.close();
    return text;
}