#pragma once
#include "GameMove.h"
#include <string>
#include <vector>
#include <iostream>
class ConnectFourMove :
    public GameMove
{
private:

    friend class ConnectFourBoard;

    int m_row_, m_col_;

    ConnectFourMove();

    ConnectFourMove(int row, int col);

public:
    static int m_on_heap_;

    static void* operator new(std::size_t sz) {
        m_on_heap_++;
        return ::operator new(sz);
    }

    static void operator delete(void* ptr, std::size_t sz) {
        m_on_heap_--;
        ::operator delete(ptr);
    }

    virtual ~ConnectFourMove() {}

    virtual GameMove& operator=(const std::string&);

    virtual bool Equals(const GameMove& other) const;

    virtual operator std::string() const;
};

