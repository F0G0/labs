#include "WorkFlowParser.h"

#include <iostream>
#include <fstream>
#include "CantOpenFile.h"

void WorkFlowParser::ReadFlowFile(std::string filename) {

    std::ifstream file;
    try {
        file.open(filename, std::ios::in);
    } catch (std::exception& exception) {
        throw CantOpenFile("Cant open this file: " + filename);
    }

    bool flag = true;

    while (!file.eof()) {
        std::string line = "";
        std::getline(file,line);

        if (line == "csed") { flag = false;}

        if (flag) {
            BlocksFromString(line);
        } else {
            SchemeFromString(line);
        }
    }
    file.close();
}


void WorkFlowParser::BlocksFromString(std::string &line) {
    if (line == "desc") {return;}

    BlockArguments block_arguments;
    std::string word = "";
    
    int position = 0;
    int id = 0;

    for (int i = 0; i <= line.size(); i++) {
        if (i == line.size() || line[i]==' ') {
            if (word.size() > 0) {
                if (position == 0) {
                    try {
                        id = std::stoi(word);
                    } catch (std::invalid_argument& exception) {
                        throw std::invalid_argument("Id must be a number.");
                    }

                } else if (position == 1) {
                    block_arguments.setName(word);
                } else {
                    block_arguments.addParam(word);
                }
                position++;
                word = "";
            }
        }
        else {
            if (line[i] != '=') {word.push_back(line[i]);}
        }
    }
    map_of_block_arguments.insert(std::make_pair(id, block_arguments));
}



void WorkFlowParser::SchemeFromString(std::string &line) {
    if (line == "csed") {return;}
    
    std::string num;
    int id;
    
    for (int i = 0; i <= line.size(); i++) {
        if (i != line.size() && isdigit(line[i])) {
            num.push_back(line[i]);
        } 
        else {
            if (num.size() > 0) {
                try {
                    id = std::stoi(num);
                } catch (std::invalid_argument& exception) {
                    throw std::invalid_argument("id must be a number");
                }
                scheme.push_back(id);
                num = "";
            }
        }
    }
}

const std::map<int, BlockArguments> &WorkFlowParser::GetBlockArguments() const {
    return map_of_block_arguments;
}


const std::list<int> &WorkFlowParser::GetScheme() const {
    return scheme;
}



