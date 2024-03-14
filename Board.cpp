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

bool Board::ValidMove(std::vector<std::vector<int>> board, int col, int row)
{
    // check right side of row
    for (int y = 0; y < row; y++)
    {
        if (board[col][y] == 1)
        {
            return false;
        }
    }
    // check diagonal going left and down
    for (int x = col, y = row; x >= 0 && y >= 0; x--, y--)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
    }
    for (int x = col, y = row; x < dimension && y >= 0; x++, y--)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
    }

    return true;
}

bool Board::PlaceQueen(std::vector<std::vector<int>> &board, int y, int queens) 
{
    // check if row is final one in board
    if (y == dimension)
    {
        // it's not so see if you added all th desired queens
        if (queens == totalQueens)
        {
            return true;
        }

        // lacking some amount of queens so this isn't solution
        return false;
    }

    // run through current row
    for (int x = 0; x < dimension; x++)
    {
        if (ValidMove(board, x, y))
        {
            //place queen
            board[x][y] = 1; 
            queens++;

            if (PlaceQueen(board, y + 1, queens))
            {
                return true;
            }

            // remove queen (backtrack)
            board[x][y] = 0;
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
