#pragma once
#include "IPlayer.h"
#include <cstdlib>
#include <ctime>
class Bot :
    public IPlayer
{
    char difficulty;
    std::vector<GameMove*> possible_moves;
public:
    Bot(char d = 'e' ) {
        difficulty = d;
    };
    void updateMoves(std::vector<GameMove*>& moves);
    char getDifficulty();
    std::string makeMove() override;
};

