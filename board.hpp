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

        bool CheckRow(int row, int val);
        bool CheckCol(int col, int val);

        bool IsValid(int row, int col, int val);
        void Print();

        void SetData(int row, int col, int val);

        std::vector<std::vector<int>> GetBoard();
        int GetData(int row, int col);
};

#endif