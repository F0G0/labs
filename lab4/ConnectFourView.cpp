#include <iostream>
#include "ConnectFourView.h"

using namespace std;

void ConnectFourView::PrintBoard(std::ostream& s) const {
	cout << endl;
	cout << "  A B C D E F G " << endl;

	for (int r = 0; r < CF_ROWS; r++) {
		cout << "  ";
		for (int c = 0; c < CF_COLS; c++) {
			if (mConnectFourBoard->m_board_[r][c] ==
				ConnectFourBoard::Player::YELLOW) {
				cout << "Y ";
			}
			else if (mConnectFourBoard->m_board_[r][c] ==
				ConnectFourBoard::Player::RED) {
				cout << "R ";
			}
			else {
				cout << ". ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void ConnectFourView::PrintMainMenu() const
{
	cout << "-------------------------------------------\n";
	cout << "              Connect four                 \n";
	cout << "-------------------------------------------\n";
	cout << "   Choose number of players from 0-2\n";
	cout << "         Write exit to quit.\n";
}

void ConnectFourView::PrintWinScreen(int value) const
{
	if (value == 1) {
		std::cout << std::endl << "Game over. " <<
			"First player" << " wins!\n" << std::endl;
	}
	else if (value == 2 ) {
		std::cout << std::endl << "Game over. " <<
			"Second player" << " wins!\n" << std::endl;
	}
	else {
		std::cout << std::endl << "Game over. We have a tie!\n" << std::endl;
	}
}

void ConnectFourView::PrintMoves(std::string player, std::vector<GameMove*>& moves) const
{
	std::cout << player << "'s move." << std::endl;

	std::cout << std::endl << "Possible moves: " << std::endl;
	for (GameMove* move : moves) {
		std::cout << move->operator std::string() << " ";
	}
}
