#include "catch/catch.hpp"
#include "../board.hpp"
#include <vector>

TEST_CASE("Board")
{
    Board defaultBoard;
    std::vector<std::vector<int>> easyBoard
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
    Board paramBoard(easyBoard);

    SECTION("Test Constructors")
    {
        CHECK(paramBoard.GetBoard().empty() == false);
        // test GetData
        CHECK(paramBoard.GetData(0,1) == 5);
        CHECK(paramBoard.GetData(0,8) == 3);
        CHECK(paramBoard.GetData(8,5) == 8);
        CHECK(paramBoard.GetBoard().empty() == false);
    }

    SECTION("setting data and out of bounds assignment")
    {
        // test SetData
        defaultBoard.SetData(0,0,2);
        defaultBoard.SetData(0,1,3);
        CHECK(defaultBoard.GetData(0,0) == 2);
        CHECK(defaultBoard.GetData(0,1) == 3);
        // test out of bounds assignment
        defaultBoard.SetData(2,2, -9);
        CHECK(defaultBoard.GetData(2,2) == 0);
    }

    SECTION("Check Rows and Columns")
    {
        // test CheckRow
        CHECK(paramBoard.CheckRow(0,5) == false);
        CHECK(paramBoard.CheckRow(0, 2) == true);
        // test CheckColumn
        CHECK(paramBoard.CheckCol(0,8) == false);
        CHECK(paramBoard.CheckCol(0,1) == true);
    }

    SECTION("Test SubBoard Checks")
    {
        CHECK(paramBoard.CheckSubBoard(0,0,1) == true);
        CHECK(paramBoard.CheckSubBoard(0,0,2) == true);
        CHECK(paramBoard.CheckSubBoard(0,0,9) == true);
        CHECK(paramBoard.CheckSubBoard(0,0,5) == false);
        CHECK(paramBoard.CheckSubBoard(0,0,8) == false);
        CHECK(paramBoard.CheckSubBoard(0,0,3) == false);

        CHECK(paramBoard.CheckSubBoard(4,1,3) == true);
        CHECK(paramBoard.CheckSubBoard(4,1,8) == false);

        CHECK(paramBoard.CheckSubBoard(6,4,1) == true);
        CHECK(paramBoard.CheckSubBoard(6,4,2) == false);
    }

    SECTION("IsValid Checks")
    {
        CHECK(paramBoard.IsValid(0,0,1) == true);
        CHECK(paramBoard.IsValid(0,0,2) == false);
        CHECK(paramBoard.IsValid(0,0,9) == true);
        CHECK(paramBoard.IsValid(0,0,5) == false);
        CHECK(paramBoard.IsValid(0,0,8) == false);
        CHECK(paramBoard.IsValid(0,0,3) == false);

        CHECK(paramBoard.IsValid(4,1,3) == true);
        CHECK(paramBoard.IsValid(4,1,8) == false); // fails subgrid check
        CHECK(paramBoard.IsValid(4,1,7) == false); // fails row check
        CHECK(paramBoard.IsValid(4,1,5) == false); // fails column check

        CHECK(paramBoard.IsValid(6,4,1) == false); // fails column check
        CHECK(paramBoard.IsValid(6,4,2) == false); // fails subgrid and col check
        CHECK(paramBoard.IsValid(6,4,6) == false); // fails row check 
        CHECK(paramBoard.IsValid(6,4,3) == true);
    }
    paramBoard.Print();
    CHECK(paramBoard.Solve() == true);
    paramBoard.Print();
    
}
