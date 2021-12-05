#include <stdexcept>
#include <regex>
#include "Replace.h"
#include "BlockMaker.h"

static BlockMaker<Replace> maker("replace");

std::list<std::string>& Replace::Execute(const std::list<std::string> &parameters,std::list<std::string>& text) {
    if (parameters.size() != 2) {throw IncorrectAmountOfParams("Replace needs only two parameters. "
                                                           + std::to_string(parameters.size()));}
    std::string target = parameters.front();
    std::string replacement = parameters.back();
    std::list<std::string> newText;
    for (auto it = text.begin(); it != text.end(); ++it) {
        newText.push_back(std::regex_replace(*it, std::regex(target), replacement));
    }
    text = newText;
    return text;
}