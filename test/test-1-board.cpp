#include "catch/catch.hpp"
#include "../board.hpp"

TEST_CASE("Board")
{
    Board emptyBoard;
    CHECK(emptyBoard.GetXSize() == 0);
    CHECK(emptyBoard.GetYSize() == 0);

    Board paramBoard(3,3);
    CHECK(paramBoard.GetXSize() == 3);
    CHECK(paramBoard.GetYSize() == 3);
    
}