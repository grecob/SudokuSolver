#ifndef BOARD_HPP
#define BOARD_HPP
#include <vector>

class Board
{
    private:
        std::vector<std::vector<int>> data;
    public:
        // constructors
        Board();
        Board(std::vector<std::vector<int>>);
        
        // utility / helpers
        bool CheckRow(int row, int val);
        bool CheckCol(int col, int val);
        bool CheckSubBoard(int row, int col, int val);
        bool IsValid(int row, int col, int val);
        void Print();

        // setters
        void SetData(int row, int col, int val);
        // getters
        std::vector<std::vector<int>> GetBoard();
        int GetData(int row, int col);
};

#endif