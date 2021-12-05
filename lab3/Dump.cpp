
#include <stdexcept>
#include <fstream>
#include "Dump.h"
#include "BlockMaker.h"

static BlockMaker<Dump> maker("dump");


std::list<std::string>& Dump::Execute(const std::list<std::string> &parameters, std::list<std::string> &text) {
    if (parameters.size() != 1) {throw IncorrectAmountOfParams("Dump needs only one param. "
    + std::to_string(parameters.size()));}

    std::string filename = parameters.back();

    std::ofstream file;
    file.open(filename, std::ios::out);

    for (auto it = text.begin(); it != text.end(); ++it) {
        file << *it << std::endl;
    }
    file.close();
    return text;
}