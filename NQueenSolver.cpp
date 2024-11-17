#include "Board.h"
#include <iostream>
#include <string>
#include <vector>

//
// variable declaration 
//
std::vector<Board> boards;

//
// function declaration
//

// prompts the user for board size and queen amount
Board ProgramSetUpPrompt();

void SolveProblem(Board &board);

//
// main  loop
//
int main(){
std::cout<<"\nN Queen Problem Solver \n\n";

Board board = ProgramSetUpPrompt();

board.Solve();

return 0;
}

//
// function implementation
//
Board ProgramSetUpPrompt(){
    int queen;
    int size;
    std::cout<<"Please input the amount of queens\n> ";
    std::cin>>queen;

    std::cout<<"Please input the chess board size\n> ";
    std::cin>>size;

    Board board(size,queen);
    return board;
}

void SolveProblem(Board &board){

    

}