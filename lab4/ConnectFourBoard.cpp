#include <vector>
#include "ConnectFourBoard.h"

ConnectFourBoard::ConnectFourBoard() : GameBoard() {
	for (int i = 0; i < CF_ROWS; i++) {
		for (int j = 0; j < CF_COLS; j++) {
			m_board_[i][j] = EMPTY;
		}
	}
}

bool ConnectFourBoard::hasWon() {
	for (short row = 0; row < CF_ROWS; row++) {
		for (short col = 0; col < CF_COLS; col++) {
			int currentColor = m_board_[row][col];
			if (currentColor == EMPTY) continue;
			if (InBounds(row + 3, col)) {
				if (m_board_[row + 1][col] == currentColor &&
					m_board_[row + 2][col] == currentColor &&
					m_board_[row + 3][col] == currentColor) {
					return true;
				}
			}

			if (InBounds(row, col + 3)) {
				if (m_board_[row][col + 1] == currentColor &&
					m_board_[row][col + 2] == currentColor &&
					m_board_[row][col + 3] == currentColor) {
					return true;
				}
			}

			if (InBounds(row + 3, col + 3)) {
				if (m_board_[row + 1][col + 1] == currentColor &&
					m_board_[row + 2][col + 2] == currentColor &&
					m_board_[row + 3][col + 3] == currentColor) {
					return true;
				}
			}

			if (InBounds(row + 3, col - 3)) {
				if (m_board_[row + 1][col - 1] == currentColor &&
					m_board_[row + 2][col - 2] == currentColor &&
					m_board_[row + 3][col - 3] == currentColor) {
					return true;
				}
			}
		}
	}
	return false;
}


void ConnectFourBoard::ApplyMove(GameMove* move) {

	ConnectFourMove* m = dynamic_cast<ConnectFourMove*>(move);

	if (m == nullptr) {
		throw GameException("Tried to apply a non-ConnectFourMove");
	}

	m_history_.push_back(move);

	int col = m->m_col_;
	int i = -1;


	while (m_board_[i + 1][col] == 0 && i < CF_ROWS - 1) {
		i++;
	}

	m->m_row_ = i;

	m_board_[m->m_row_][m->m_col_] = m_next_player_;

	if (hasWon()) {
		if (m_next_player_ == YELLOW) {
			m_value_ += 1;
		}
		else m_value_ += 2;
	}

	(m_next_player_ == RED) ? m_next_player_ = YELLOW : m_next_player_ = RED;
}



void ConnectFourBoard::GetPossibleMoves(std::vector<GameMove*>* list) const {
	for (int i = 0; i < CF_COLS; i++) {
		if (m_board_[0][i] == EMPTY) {
			ConnectFourMove* move = dynamic_cast<ConnectFourMove*>(CreateMove());
			move->m_col_ = i;
			move->m_row_ = 0;
			list->push_back(move);
		}
	}
}
