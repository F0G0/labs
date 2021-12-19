#ifndef __GAMEBOARD_H
#define __GAMEBOARD_H

#include "GameMove.h"
#include "GameException.h"
#include <vector>

class GameBoard {
public:
	virtual ~GameBoard() {
		for (GameMove* m : m_history_) {
			delete m;
		}
		m_history_.clear();
	}

	GameBoard() : m_next_player_(1), m_value_(0) {}

	virtual void GetPossibleMoves(std::vector<GameMove*>* list) const = 0;

	virtual void ApplyMove(GameMove* move) = 0;

	virtual GameMove* CreateMove() const = 0;

	virtual bool IsFinished() const = 0;

	inline int GetValue() const { return m_value_; }

	inline int GetNextPlayer() const { return m_next_player_; }

	inline const std::vector<GameMove*>* GetMoveHistory() const {
		return &m_history_;
	}

	inline int GetMoveCount() const {
		return m_history_.size();
	}

	virtual std::string GetPlayerString(char player) {
		return (player == 1 ? "Black" : "White");
	}

protected:
	int m_next_player_;
	int m_value_;
	std::vector<GameMove*> m_history_;
};

#endif