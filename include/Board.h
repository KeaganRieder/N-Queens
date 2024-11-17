#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>

// Chess Board declaration
class Board
{
private:
    int dimension; // The size of the board (NxN)
    int totalQueens; // Total number of queens to place
    std::vector<std::vector<int>> boardBody; // The board representation

    // Initializes the board with zeros
    void InitializeBoard();

    // Checks if placing a queen at (row, col) is valid
    bool ValidMove(const std::vector<std::vector<int>> &board, int row, int col);

    // Recursively attempts to place queens using backtracking
    bool PlaceQueen(std::vector<std::vector<int>> &board, int col);

public:
    // Constructor: initializes the board based on provided size and queen count
    Board(int boardSize, int queens);

    // Destructor
    ~Board();

    // Triggers the backtracking algorithm to solve the N-Queens problem
    void Solve();

    // Prints the solution if it exists; otherwise, prints that no solution exists
    void PrintSolution();
};

#endif
