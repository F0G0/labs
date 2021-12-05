#include <memory>
#include "WorkFlow.h"
#include "BlockFactory.h"




void WorkFlow::exeWorkFlow(const std::string &filename) {

    parser.ReadFlowFile(filename);
    auto scheme = parser.GetScheme();
    auto map_block_arguments = parser.GetBlockArguments();

    StreamType out_type = StreamType::NO_TYPE;
    StreamType in_type;
    std::list<std::string> text;

    for (auto it = scheme.begin(); it != scheme.end(); ++it) {
        BlockArguments block_arguments = map_block_arguments.at(*it);
        std::unique_ptr<Worker> block(BlockFactory::Instance().create(block_arguments.getName()));
        in_type = block->GetInType(in_type);
        if (in_type != out_type) {
            throw UnavailableWorkFlow("Workflow is incorrect. Wrong stream types.");
        }
        out_type = block->GetOutType(out_type);
        text = block->Execute(block_arguments.getParams(), text);
    }
}

