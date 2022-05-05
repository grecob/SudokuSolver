#include "catch/catch.hpp"
#include "../board.hpp"
#include <vector>

TEST_CASE("Board")
{
    Board defaultBoard;
    CHECK(defaultBoard.GetBoard().empty() == false);
    CHECK(defaultBoard.GetData(0,1) == 5);
    CHECK(defaultBoard.GetData(0,8) == 3);
    CHECK(defaultBoard.GetData(8,5) == 8);

    std::vector<std::vector<int>> emptyBoard{{}};
    Board paramBoard(emptyBoard);    
    CHECK( paramBoard.GetBoard().empty() == true);

}