#pragma once
#include "GameBoard.h"
#include "GameMove.h"
#include <iostream>
class GameView {
private:
    virtual void PrintBoard(std::ostream& s) const = 0;
public:
    virtual void PrintMainMenu() const = 0;
    virtual void PrintWinScreen(int value) const = 0;
    virtual void PrintMoves(std::string player, std::vector<GameMove*>& moves)const = 0;
    virtual ~GameView() {}
    friend std::ostream& operator<< (std::ostream& os, const GameView& v) {
        v.PrintBoard(os);
        return os;
    }
};