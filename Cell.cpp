#include "Cell.h"

Cell::Cell(int xCord, int yCord, bool validPlace)
{
    this->xCord = xCord;
    this->yCord = yCord;
    this->validPlace = validPlace;
}

Cell::~Cell()
{
}

std::pair<int, int> Cell::GetCord()
{
    std::pair<int, int> cord;
    cord.first = xCord;
    cord.second = yCord;
    return cord;
}
std::pair<int, int> Cell::GetUpCords()
{
    std::pair<int, int> cord;
    cord.first = xCord;
    cord.second = yCord - 1;
    return cord;
}
std::pair<int, int> Cell::GetDownCords()
{
    std::pair<int, int> cord;
    cord.first = xCord;
    cord.second = yCord + 1;
    return cord;
}
std::pair<int, int> Cell::GetLeftCords()
{
    std::pair<int, int> cord;
    cord.first = xCord - 1;
    cord.second = yCord;
    return cord;
}
std::pair<int, int> Cell::GetRightCords()
{
    std::pair<int, int> cord;
    cord.first = xCord + 1;
    cord.second = yCord;
    return cord;
}
std::pair<int, int> Cell::GetULDiagonalCords()
{
    std::pair<int, int> cord;
    cord.first = xCord - 1;
    cord.second = yCord - 1;
    return cord;
}
std::pair<int, int> Cell::GetURDiagonalCords()
{
    std::pair<int, int> cord;
    cord.first = xCord + 1;
    cord.second = yCord - 1;
    return cord;
}
std::pair<int, int> Cell::GetDLDiagonalCords()
{
    std::pair<int, int> cord;
    cord.first = xCord - 1;
    cord.second = yCord + 1;
    return cord;
}
std::pair<int, int> Cell::GetDRDiagonalCords()
{
    std::pair<int, int> cord;
    cord.first = xCord + 1;
    cord.second = yCord + 1;
    return cord;
}
