#include <stdexcept>
#include "Grep.h"

#include "BlockMaker.h"

static BlockMaker<Grep> maker("grep");

std::list<std::string>& Grep::Execute(const std::list<std::string> &parameters, std::list<std::string>& text) {
    if (parameters.size() != 1) {throw IncorrectAmountOfParams("Grep needs only one param. "
                                                           + std::to_string(parameters.size()));}
    std::string word = parameters.front();

    std::list<std::string> newText;
    for (auto it = text.begin(); it != text.end(); ++it) {
        std::string str = *it;
        size_t pos = str.find(word);
        if (pos != std::string::npos) {
            newText.push_back(str);
        }
    }
    text = newText;
    return text;
}