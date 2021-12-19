#pragma once
#include <vector>
#include "ConnectFourMove.h"
#include "GameBoard.h"
#include "GameMove.h"

const int CF_ROWS = 6;
const int CF_COLS = 7;

class ConnectFourBoard : public GameBoard {

public:

	virtual ~ConnectFourBoard() {}

	enum Player { EMPTY = 0, YELLOW = 1, RED = 2 };
	enum Row { A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6 };

	ConnectFourBoard();

	virtual void GetPossibleMoves(std::vector<GameMove*>* list) const;

	virtual void ApplyMove(GameMove* move);

	virtual GameMove* CreateMove() const { return new ConnectFourMove; }

	inline static bool InBounds(int row, int col) {
		return row >= 0 && row < CF_ROWS&& col >= 0 && col < CF_COLS;
	}

	virtual std::string GetPlayerString(char player) {
		return (player == 1 ? "Yellow" : "Red");
	}

	bool hasWon();

	virtual bool IsFinished() const {
		return (m_value_ != 0) || GetMoveCount() == CF_ROWS * CF_COLS;
	}

private:
	friend class ConnectFourView;

	char m_board_[CF_ROWS][CF_COLS];
};