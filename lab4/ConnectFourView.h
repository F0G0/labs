#pragma once
#include "ConnectFourBoard.h"
#include "GameView.h"
#include <iostream>

class ConnectFourView : public GameView {
private:
	ConnectFourBoard* mConnectFourBoard;
	void PrintBoard(std::ostream& s) const;

public:
	virtual ~ConnectFourView() {}
	void PrintMainMenu() const;
	void PrintWinScreen(int value) const;
	void PrintMoves(std::string player, std::vector<GameMove*>& moves)const;
	ConnectFourView(GameBoard* b) : mConnectFourBoard(dynamic_cast<ConnectFourBoard*>(b)) {}
};