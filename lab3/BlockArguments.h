#pragma once

#include <string>
#include <list>

struct BlockArguments {
private:
    std::string name;
    std::list<std::string> parameters;
public:
    BlockArguments() {
        this->name = "";
    }
    BlockArguments(const std::string& name) {
        this->name = name;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        BlockArguments::name = name;
    }

    const std::list<std::string> &getParams() const {
        return parameters;
    }


    void addParam(const std::string& param) {
        BlockArguments::parameters.push_back(param);
    }

};


