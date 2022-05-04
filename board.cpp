#include "board.hpp"

Board::Board()
{  
    this->x = 0;
    this->y = 0;
}

Board::Board(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Board::GetXSize() { return this->x; }
int Board::GetYSize() { return this->y; }