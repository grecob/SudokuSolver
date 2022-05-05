#include "board.hpp"
#include <iostream>
Board::Board()
{
    data =
        {
            {0,5,0,7,6,0,0,0,3},
            {0,0,8,0,0,9,1,0,0},
            {3,0,0,0,0,4,9,6,2},
            {0,9,4,3,0,5,0,0,6},
            {8,0,7,0,2,0,0,4,0},
            {2,0,0,4,1,0,3,0,8},
            {0,0,6,0,0,0,0,7,0},
            {4,1,0,0,0,2,0,0,5},
            {0,2,0,5,9,8,0,1,4}
        };
}

Board::Board(std::vector<std::vector<int>> paramBoard)
{
    this->data = paramBoard;
}

void Board::SetData(int row, int col, int val)
{
    if(row < 9 && row >=0 && col < 9 && col >= 0)
    {
        if(val < 9 && val >= 0)
        {
            this->data[row][col] = val;
        }
    }
    return;
}

std::vector<std::vector<int>> Board::GetBoard()
{
    return data;
}

int Board::GetData(int row, int col)
{
    return data[row][col];
}



