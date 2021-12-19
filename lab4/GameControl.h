#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "GameException.h"
#include "GameBoard.h"
#include "GameView.h"
#include "GameMove.h"
#include "ConnectFourBoard.h"
#include "ConnectFourMove.h"
#include "ConnectFourView.h"
#include "IPlayer.h"
#include "Bot.h"
#include "Player.h"

class GameControl
{
private:
	GameBoard* board;
	GameView* game_view;
	std::vector<GameMove*> possible_moves;
	std::vector<IPlayer*> players;
public:
	bool init();
	bool gameLoop();

};

