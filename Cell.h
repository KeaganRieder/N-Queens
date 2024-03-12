#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <utility>

// A cell contain information about a postion on the board
class Cell
{
private:
    // the x cord of the cell on the board
    int xCord;
    // the y cord of the cell on the board
    int yCord;
    // used to determine if this cell is a valid place for a queen
    // or if there is one already present in the same diagonal, col or row
    bool validPlace;

public:
    // constructor
    Cell(int xCord, int yCord, bool validPlace);
    // destructor
    ~Cell();

    // returns this cells cord
    std::pair<int,int> GetCord();

    // returns the cords of the cell above this one
    std::pair<int,int> GetUpCords();

    // returns the cords of the cell below this one
    std::pair<int,int> GetDownCords();

    // returns the cords of the cell left of this one
    std::pair<int,int> GetLeftCords();

    // returns the cords of the cell right of this one
    std::pair<int,int> GetRightCords();

    // returns the cords of the cell on the diagonal going up and left
    std::pair<int,int> GetULDiagonalCords();

    // returns the cords of the cell on the diagonal going up and right
    std::pair<int,int> GetURDiagonalCords();

    // returns the cords of the cell on the diagonal going down and left
    std::pair<int,int> GetDLDiagonalCords();

    // returns the cords of the cell on the diagonal going down and right
    std::pair<int,int> GetDRDiagonalCords();
};

#endif