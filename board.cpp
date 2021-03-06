#include "board.hpp"
#include <iostream>

const int BOARD_SIZE = 9;
const int SUB_BOARD_SIZE = 3;
Board::Board()
{
    data =
    {
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0}
    };
}

Board::Board(std::vector<std::vector<int>> paramBoard)
{
    this->data = paramBoard;
}


bool Board::CheckRow(int row, int val)
{
    for(int i = 0; i < BOARD_SIZE; ++i)
    {
        if(data[row][i] == val)
        {
            return false;
        }
    }
    return true;
}

bool Board::CheckCol(int col, int val)
{
    for(int i = 0; i < BOARD_SIZE; ++i)
    {
        if(data[i][col] == val)
        {
            return false;
        }
    }
    return true;
}

bool Board::CheckSubBoard(int row, int col, int val)
{
    for(int i = 0; i< SUB_BOARD_SIZE; ++i)
    {
        for(int j = 0; j < SUB_BOARD_SIZE; ++j)
        {
            // check every value in the sub board given the row and col
            if(data[i+(row - row % SUB_BOARD_SIZE)][j+(col - col % SUB_BOARD_SIZE)] == val)
            {
                return false;
            }
        }
    }
    return true;
}


bool Board::IsValid(int row, int col, int val)
{
    // check row, col, subboard
    return CheckRow(row,val) && CheckCol(col,val) && CheckSubBoard(row,col,val);
}


void Board::SetData(int row, int col, int val)
{
    if(row < BOARD_SIZE && row >=0 && col < BOARD_SIZE && col >= 0)
    {
        if(val < BOARD_SIZE && val >= 0)
        {
            this->data[row][col] = val;
        }
    }
    return;
}

void Board::Print()
{
    for(int i = 0; i < BOARD_SIZE; ++i)
    {
        if(i % 3 == 0)
        {
            std::cout << "\n+-------+-------+-------+";
        }
        std::cout << '\n';
        for(int j = 0; j < BOARD_SIZE; ++j)
        {
            if(j % 3 == 0)
            {
                std::cout << "| ";
            }
            std::cout << data[i][j]<< " ";
        }
        std::cout << "|";
    }
    std::cout << "\n+-------+-------+-------+\n";
}

bool Board::Solve(int row,int col)
{
    // base case
    if(row == 9)
    {
        return true;
    }
    else if(col  == 9)
    {
        return Solve(row + 1, 0);
    }
    else if(data[row][col] != 0)
    {
        return Solve(row, col + 1);
    }
    else
    {
        for(int i = 1; i < 10; ++i)
        {
            if(IsValid(row,col,i))
            {
                data[row][col] = i;
                if(Solve(row, col + 1))
                {
                    return true;
                }
                data[row][col] = 0;
            }
        }
        return false;
    }
}

std::vector<std::vector<int>> Board::GetBoard()
{
    return data;
}

int Board::GetData(int row, int col)
{
    return data[row][col];
}



