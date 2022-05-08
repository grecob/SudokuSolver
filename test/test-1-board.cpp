#include "catch/catch.hpp"
#include "../board.hpp"
#include <vector>

TEST_CASE("Board")
{
    Board defaultBoard;
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

    SECTION("Test Constructors")
    {
        CHECK(defaultBoard.GetBoard().empty() == false);
        // test GetData
        CHECK(defaultBoard.GetData(0,1) == 5);
        CHECK(defaultBoard.GetData(0,8) == 3);
        CHECK(defaultBoard.GetData(8,5) == 8);
        CHECK( paramBoard.GetBoard().empty() == false);
    }

    SECTION("setting data and out of bounds assignment")
    {
        // test SetData
        paramBoard.SetData(0,0,2);
        paramBoard.SetData(0,1,3);
        CHECK(paramBoard.GetData(0,0) == 2);
        CHECK(paramBoard.GetData(0,1) == 3);
        // test out of bounds assignment
        paramBoard.SetData(2,2, -9);
        CHECK(paramBoard.GetData(2,2) == 0);
    }

    SECTION("Check Rows and Columns")
    {
        // test CheckRow
        CHECK(defaultBoard.CheckRow(0,5) == false);
        CHECK(defaultBoard.CheckRow(0, 2) == true);
        // test CheckColumn
        CHECK(defaultBoard.CheckCol(0,8) == false);
        CHECK(defaultBoard.CheckCol(0,1) == true);
    }

    SECTION("Test SubBoard Checks")
    {
        CHECK(defaultBoard.CheckSubBoard(0,0,1) == true);
        CHECK(defaultBoard.CheckSubBoard(0,0,2) == true);
        CHECK(defaultBoard.CheckSubBoard(0,0,9) == true);
        CHECK(defaultBoard.CheckSubBoard(0,0,5) == false);
        CHECK(defaultBoard.CheckSubBoard(0,0,8) == false);
        CHECK(defaultBoard.CheckSubBoard(0,0,3) == false);

        CHECK(defaultBoard.CheckSubBoard(4,1,3) == true);
        CHECK(defaultBoard.CheckSubBoard(4,1,8) == false);

        CHECK(defaultBoard.CheckSubBoard(6,4,1) == true);
        CHECK(defaultBoard.CheckSubBoard(6,4,2) == false);
    }

    SECTION("IsValid Checks")
    {
        CHECK(defaultBoard.IsValid(0,0,1) == true);
        CHECK(defaultBoard.IsValid(0,0,2) == false);
        CHECK(defaultBoard.IsValid(0,0,9) == true);
        CHECK(defaultBoard.IsValid(0,0,5) == false);
        CHECK(defaultBoard.IsValid(0,0,8) == false);
        CHECK(defaultBoard.IsValid(0,0,3) == false);

        CHECK(defaultBoard.IsValid(4,1,3) == true);
        CHECK(defaultBoard.IsValid(4,1,8) == false); // fails subgrid check
        CHECK(defaultBoard.IsValid(4,1,7) == false); // fails row check
        CHECK(defaultBoard.IsValid(4,1,5) == false); // fails column check

        CHECK(defaultBoard.IsValid(6,4,1) == false); // fails column check
        CHECK(defaultBoard.IsValid(6,4,2) == false); // fails subgrid and col check
        CHECK(defaultBoard.IsValid(6,4,6) == false); // fails row check 
        CHECK(defaultBoard.IsValid(6,4,3) == true);
    }
    defaultBoard.Print();
    CHECK(defaultBoard.Solve() == true);
    defaultBoard.Print();
    
}
