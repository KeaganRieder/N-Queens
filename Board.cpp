#include "Board.h"

Board::Board(int boardSize, int queen)
{
    dimension = boardSize;
    totalQueens = queen;

    InitializeBoard();
}
Board::~Board()
{
}

void Board::InitializeBoard()
{
    for (int x = 0; x < dimension; x++)
    {
        std::vector<int> boardY;
        for (int y = 0; y < dimension; y++)
        {
            boardY.push_back(0);
        }
        boardBody.push_back(boardY);
    }
}

bool Board::ValidMove(std::vector<std::vector<int>> board, int row, int col)
{
    // check columns
    for (int y = 0; y < col; y++)
    {
        if (board[row][y] == 1)
        {
            return false;
        }
    }
    // check diagonal going left and down
    for (int x = row, y = col; x >= 0 && y >= 0; x--, y--)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
    }
    for (int x = row, y = col; x < dimension && y >= 0; x++, y--)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
    }

    return true;
}

bool Board::PlaceQueen(std::vector<std::vector<int>> &board, int col, int queens) // maybe switch rows with columns
{
    // check if columns are still less then dimension
    if (col == dimension)
    {
        // it's not so see if you added all th desired queens
        if (queens == totalQueens)
        {
            return true;
        }

        // lacking some amount of queens so this isn't solution
        return false;
    }

    // they are still les so run through all rows
    for (int row = 0; row < dimension; row++)
    {
        if (ValidMove(board, row, col))
        {
            board[row][col] = 1;
            queens++;

            if (PlaceQueen(board, col + 1, queens))
            {
                return true;
            }

            // backtracking
            board[row][col] = 0;
            queens--;
        }
    }

    return false;
}

void Board::Solve()
{
    if (PlaceQueen(boardBody, 0, 0))
    {
        PrintSolution();
    }
    else
    {
        std::cout << "\n> There is no solution on a "
                  << dimension << " X " << dimension << " board with " << totalQueens << " Queens\n";
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
                std::cout << "_ | ";
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
