#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
    private:
        int x;
        int y;
    public:
        Board();
        Board(int x,int y);
        int GetXSize();
        int GetYSize();
};

#endif