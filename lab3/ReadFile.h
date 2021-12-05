#pragma once

#include "Worker.h"

class ReadFile : public Worker{

public:
    ReadFile() = default;
    std::list<std::string>& Execute(const std::list<std::string>& parameters, std::list<std::string>& text) override;
    StreamType& GetInType(StreamType& in_type) override {
        in_type = StreamType::NO_TYPE;
        return in_type;
    }
    StreamType& GetOutType(StreamType& out_type) override {
        out_type = StreamType::TEXT;
        return out_type;
    }

};

