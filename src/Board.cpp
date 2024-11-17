#include "Board.h"
#include <iostream>
#include <vector>
#include <string>

// Constructor
Board::Board(int boardSize, int queen) : dimension(boardSize), totalQueens(queen)
{
    InitializeBoard();
}

// Destructor
Board::~Board() {}

// Initialize the board with zeros
void Board::InitializeBoard()
{
    boardBody = std::vector<std::vector<int>>(dimension, std::vector<int>(dimension, 0));
}

// Check if placing a queen at (row, col) is valid
bool Board::ValidMove(const std::vector<std::vector<int>> &board, int row, int col)
{
    // Check the same row to the left
    for (int y = 0; y < col; ++y)
    {
        if (board[row][y] == 1)
        {
            return false;
        }
    }

    // Check upper-left diagonal
    for (int x = row, y = col; x >= 0 && y >= 0; --x, --y)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
    }

    // Check lower-left diagonal
    for (int x = row, y = col; x < dimension && y >= 0; ++x, --y)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
    }

    return true;
}

// Recursively attempt to place queens using backtracking
bool Board::PlaceQueen(std::vector<std::vector<int>> &board, int col)
{
    // Base case: all queens are placed
    if (col == totalQueens)
    {
        return true;
    }

    // Try placing a queen in each row of the current column
    for (int row = 0; row < dimension; ++row)
    {
        if (ValidMove(board, row, col))
        {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the next queen
            if (PlaceQueen(board, col + 1))
            {
                return true;
            }

            // Backtrack if placing queen here doesn't lead to a solution
            board[row][col] = 0;
        }
    }

    // No valid placement found in this column
    return false;
}

// Solve the N-Queens problem
void Board::Solve()
{
    if (PlaceQueen(boardBody, 0))
    {
        PrintSolution();
    }
    else
    {
        std::cout << "\n> No solution exists for a " << dimension
                  << " X " << dimension << " board with " << totalQueens << " Queens.\n";
    }
}

void Board::PrintSolution()
{
    std::cout << "\n> The following is the solution on a "
              << dimension << " X " << dimension << " board with " << totalQueens << " Queens\n\n";

    for (int x = 0; x < dimension; x++)
    {
        std::cout << std::string(4, '-');
    }
    std::cout << "-";

    for (int x = 0; x < dimension; x++)
    {
        std::cout << "\n| ";
        for (int y = 0; y < dimension; y++)
        {
            if (boardBody[x][y])
            {
                std::cout << "Q | ";
            }
            else
            {
                std::cout << ". | ";
            }
        }

        std::cout << "\n-";
        for (int x = 0; x < dimension; x++)
        {
            std::cout << std::string(4, '-');
        }
    }
    std::cout << "\n";
}

// // Print the solution board
// void Board::PrintSolution()
// {
//     std::cout << "\n> Solution for a " << dimension
//               << " X " << dimension << " board with " << totalQueens << " Queens:\n\n";

//     for (int x = 0; x < dimension; ++x)
//     {
//         for (int y = 0; y < dimension; ++y)
//         {
//             std::cout << (boardBody[x][y] == 1 ? " Q " : " . ");
//         }
//         std::cout << "\n";
//     }
// }
