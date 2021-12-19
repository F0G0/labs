#pragma once
#include <vector>
#include <string>
#include"GameMove.h"
class IPlayer
{
public:
	virtual void updateMoves(std::vector<GameMove*>& moves) = 0;
	virtual std::string makeMove() = 0;
	virtual ~IPlayer() = default;
};