# N-Queens Problem Solver

## table of contents 
1. [Overview](#Overview)
1. [Solving By BackTracking](#Solving_By_BackTracking)

## Overview  
The n queens problem describe as when provided amount of queens represented as 'n' place them on a chessboard of size
s x s, such that no two queens are threatening one another

The solution fo this problem is one in which place all n queens on a s x s board where no two queen are in the same column,
row or diagonal. Which leads to the following restrictions about what s and n can equal in order to have a solution
1. if s >= 1 then n = 1
2. if s = 3 then n <= 2 
3. if s = 4 then n < s
4. for all instances where s >= 5, n <= s

with the restrictions on n and s now in place, the solution fir this problem can be found through the use of the backtracking algorithm.

## Solving By BackTracking
The backtracking algorithm is a modified version of the Depth first search algorithm, which runs through all possible
moves and if one doesn't work it back tracks. the algorithm impletion can be found in [Board.cpp](Board.cpp) in the function
[PlaceQueen](#PlaceQueen)

### PlaceQueen

``` C++
bool Board::PlaceQueen(std::vector<std::vector<int>> &board, int y, int queens){
```

* "std::vector<std::vector<int>> &board" is current state of teh board the algorithm is at
* "int y"  represents the current row on the board the algorithm is on
* "int queens" is amount of queens currently placed

``` C++
    if (y == dimension)
    {
        if (queens == totalQueens)
        {
            return true;
        }

        return false;
    }
```

This if block in Place queen checks for if the col (current column) == dimension (user specified size of the  board) 
if it doesn't then continue recursively running through board's states otherwise stop recursion and check if 
queens (states current amount of queens placed) == totalQueens (goal amount of queens specified by user)
if true then this is the solution of the user given scenario for the problem otherwise return false meaning that it's not

``` c++
  for (int x = 0; x < dimension; x++)
    {
        if (ValidMove(board, x, y))
        {
            board[x][y] = 1;
            queens++;

            if (PlaceQueen(board, y + 1, queens))
            {
                return true;
            }

            // backtracking
            board[x][y] = 0;
            queens--;
        }
    }
    return false;
}
```

This part of place queen handles running through each column checking if it's a [ValidMove](#ValidMove), if it is a valid cell then do 
the following:
1. Place queen at current cell and then head to next row (next of the board state). 
2. Ensuring none of the states are a solution which will result in the for loop terminating early and PlaceQueen return as true

If it's a valid move then move to next cell, and try to place queen continuing this until either theres a valid move or you've reach the end
of the board which result in PlaceQueen return false which mean theres no solution present for specified board size (dimension) and 
queen amount (total queens)

#### ValidMove
valid move is function which is used to ensure that queen are placed in valid position such that no two queens are in the same row,colum or diagonal
it is implemented as followed

```c++
bool Board::ValidMove(std::vector<std::vector<int>> board, int col, int row){
```

* "std::vector<std::vector<int>> board" is current state of teh board the algorithm is at
* "int row" is the current position in the row needing checked  
* "int col" is the current position in the column needing checked

```c++
    for (int y = 0; y < row; y++)
    {
        if (board[col][y] == 1)
        {
            return false;
        }
    }
```
this for loop is used to check to check if theres any queens in any positions to the left of the point which the queen 
currently trying to be placed at if there is then return false (not valid) otherwise head to the next check

```c++
    for (int x = col, y = row; x >= 0 && y >= 0; x--, y--)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
    }
```

this for loop checks the upper diagonal on left side to see if there are any queens place in
those cells if theres is return false (not valid) otherwise move to final check

```c++
    for (int x = col, y = row; x < dimension && y >= 0; x++, y--)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
    }

    return true;
}
```

this for loop checks the lower diagonal on left side to ensure theres no queens which are placed in those cells
if theres is return false (not valid) otherwise return true (valid move) sense all other checks were passed
