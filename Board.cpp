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
        std::vector<char> boardY;
        for (int y = 0; y < dimension; y++)
        {
            boardY.push_back('_');
        }
        boardBody.push_back(boardY);
    }
}

bool Board::ValidMove(std::vector<std::vector<char>> boardBody, int x, int y)
{
    int row;
    int col;

    // checking, columns
    for (col = 0; col < dimension; col++)
    {
        if (boardBody[x][col] == 'Q')
        {
            return false;
        }
    }

    // checking Up, left diagonal
    for (row = x, col = y; row >= 0 && col >= 0; row--, col--)
    {
        if (boardBody[row][col] == 'Q')
        {
            return false;
        }
    }

    // checking up, right diagonal
    for (row = x, col = y; row <= dimension && col >= 0; row++, col--)
    {
        if (boardBody[row][col] == 'Q')
        {
            return false;
        }
    }

    // checking down, left diagonal
    for (row = x, col = y; row >= 0 && col <= dimension; row--, col++)
    {
        if (boardBody[row][col] == 'Q')
        {
            return false;
        }
    }

    // checking down, right diagonal
    for (row = x, col = y; row <= dimension && col <= dimension; row++, col++)
    {
        if (boardBody[row][col] == 'Q')
        {
            return false;
        }
    }

    return true;
}

bool Board::PlaceQueen(std::vector<std::vector<char>> &board, int col, int queens)
{
    //check if columns are still less then dimension
    if (col >= dimension)
    {
        // it's not so see if you added all th desired queens
        if (queens == totalQueens)
        {
            return true;
        }        
        
        //lacking some amount of queens so this isn't solution
        return false;
    }
    
    //they are still les so run through all rows
    for (int row = 0; row < dimension; row++)
    {
        if (ValidMove(board, row, col))
        {
            board[row][col] = 'Q';
            queens++;

            if (PlaceQueen(board, col+1,queens))
            {
                return true;
            }

            //backtracking
            board[row][col] = '_';
            queens--;            
        }
    }

    return false;
}

void Board::Solve()
{
    if(PlaceQueen(boardBody, 0, 0)){
        PrintSolution();
    }
    else{
        //print no solution 
    }
}

void Board::PrintSolution()
{
    std::cout << "\n> The following is the solution on a "
              << dimension << "X" << dimension << " board for " << totalQueens << " Queens\n\n";

    for (int x = 0; x < dimension; x++)
    {
        std::cout << "| ";
        for (int y = 0; y < dimension; y++)
        {
            std::pair<int, int> cord;
            cord.first = x;
            cord.second = y;
            // cord = boardBody[x][y].GetCord();
            std::cout << cord.first << ", " << cord.second << " | ";
        }
        std::cout << "\n";
    }
}
