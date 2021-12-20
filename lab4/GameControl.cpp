#include "GameControl.h"

bool GameControl::init()
{
	board = new ConnectFourBoard();
	game_view = new ConnectFourView(board);

	std::srand(std::time(nullptr));
	std::string user_input;
	bool exit = false;

	game_view->PrintMainMenu();

	std::getline(std::cin, user_input);


	if (user_input.find("exit") == 0 || user_input.find("quit") == 0) {
		exit = true;
	}

	if (exit) {
		return false;
	}

	for (int i = 0; i < std::stoi(user_input); ++i) {
		players.push_back(new Player);
	}
	int size = players.size();
	for (int i = 0; i < (2 - size); ++i) {
		players.push_back(new Bot);
	}
	return true;
}

bool GameControl::gameLoop()
{
	std::string user_input;
	bool quit = false;
	do {
		std::cout << *game_view << std::endl;

		int current_player = board->GetNextPlayer();
		board->GetPossibleMoves(&possible_moves);

		game_view->PrintMoves(board->GetPlayerString(current_player), possible_moves);

		do {
			std::cout << std::endl << "Enter a command (move *possible move*): ";
			players[current_player%2]->updateMoves(possible_moves);
			user_input = players[current_player%2]->makeMove();

			if (user_input.find("move") == 0) {
				GameMove* move = board->CreateMove();
				bool isValid = false;
				*move = user_input.substr(5, user_input.size() - 5);
				try {

					for (GameMove* m : possible_moves) {
						if (*move == *m) {
							isValid = true;
							break;
						}
					}

					if (isValid) {
						board->ApplyMove(move);
						break;
					}
					else {
						std::cout << std::endl << "Not a valid move." << std::endl;
						delete move;
						for (GameMove* m : possible_moves) {
							delete m;
						}
						possible_moves.clear();
					}

				}
				catch (GameException& e) {
					std::cout << std::endl << e.what() << std::endl << std::endl;
					delete move;
					for (GameMove* m : possible_moves) {
						delete m;
					}
					possible_moves.clear();
				}

			}

			else if (user_input.find("quit") == 0) {
				quit = true;
			}

			else {
				std::cout << std::endl << "Invalid input.";
			}

		} while (!quit);

		std::cout << std::endl << std::endl;
		for (GameMove* m : possible_moves) {
			delete m;
		}
		possible_moves.clear();

	} while (!board->IsFinished() && !quit);

	std::cout << *game_view << std::endl;

	int value = board->GetValue();
	game_view->PrintWinScreen(value);

	delete board;
	delete game_view;
	for (int i = 0; i < players.size(); ++i) {
		delete players[i];
	}
	players.clear();
	return 0;
}
