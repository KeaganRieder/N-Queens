#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

// chess Board declaration
class Board
{
private:
    int dimension;

    int totalQueens;
    int currentQueens;

    std::vector<std::vector<int>> boardBody;
    // std::vector<Cell> queens;

public:
    // board constructor, Initializing the board based on provided size
    Board(int boardSize, int queens);

    // destructor
    ~Board();

    // making sure move is valid and doesn't results in queens placement
    // that breaks rules
    bool ValidMove(std::vector<std::vector<int>> boardBody, int x, int y);
    
    // after checking if valid places the queen at provided cords
    //returns true if solutions found other wise false
    bool PlaceQueen(std::vector<std::vector<int>> &board, int col,int queens);

    // function which is used to trigger the backtracking algorithm
    void Solve();

    // prints the solution if there is other wise prints there isn't
    void PrintSolution();

private:
    // Initializes the board
    void InitializeBoard();
};

#endif