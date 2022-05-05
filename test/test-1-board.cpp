#include "catch/catch.hpp"
#include "../board.hpp"
#include <vector>

TEST_CASE("Board")
{
    Board defaultBoard;
    CHECK(defaultBoard.GetBoard().empty() == false);
    // test GetData
    CHECK(defaultBoard.GetData(0,1) == 5);
    CHECK(defaultBoard.GetData(0,8) == 3);
    CHECK(defaultBoard.GetData(8,5) == 8);


    std::vector<std::vector<int>> emptyBoard 
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
    Board paramBoard(emptyBoard);
    CHECK( paramBoard.GetBoard().empty() == false);
    
    
    // test SetData
    paramBoard.SetData(0,0,2);
    paramBoard.SetData(0,1,3);
    CHECK(paramBoard.GetData(0,0) == 2);
    CHECK(paramBoard.GetData(0,1) == 3);
    // test out of bounds assignment
    paramBoard.SetData(2,2, -9);
    CHECK(paramBoard.GetData(2,2) == 0);
    
    

}