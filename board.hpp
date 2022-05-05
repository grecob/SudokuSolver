#ifndef BOARD_HPP
#define BOARD_HPP
#include <vector>

class Board
{
    private:
        std::vector<std::vector<int>> data;
    public:
        Board();
        Board(std::vector<std::vector<int>>);
        void SetData(int row, int col, int val);
        std::vector<std::vector<int>> GetBoard();
        int GetData(int row, int col);
};

#endif