#pragma once
#include <iostream>
#include "IPlayer.h"
class Player :
    public IPlayer
{
    void updateMoves(std::vector<GameMove*>& moves);
    std::string makeMove() override;
};

