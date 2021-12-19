#include "Bot.h"

void Bot::updateMoves(std::vector<GameMove*>& moves)
{
    possible_moves.resize(moves.size());
    possible_moves.clear();
    for (int i{}; i < moves.size(); ++i) {
        possible_moves.push_back(moves[i]);
    }
}

char Bot::getDifficulty()
{
    return difficulty;
}

std::string Bot::makeMove()
{
    if (difficulty == 'e') {
        return ("move " + possible_moves[rand() % possible_moves.size()]->operator std::string());
    }
    return "";
}
