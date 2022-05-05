#include "board.hpp"

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

std::vector<std::vector<int>> Board::GetBoard()
{
    return data;
}

int Board::GetData(int row, int col)
{
    return data[row][col];
}

