#include "Player.h"

void Player::updateMoves(std::vector<GameMove*>& moves)
{
}

std::string Player::makeMove()
{
	std::string tmp;
	std::getline(std::cin, tmp);
	return tmp;
}
