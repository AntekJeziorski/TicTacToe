#include <iostream>
#include <bits/stdc++.h>
#include "ticTacToe.hh"

int main() {

    ticTacToe game(3);
    int row, col;
    
    move AImove;

    AImove.bestCol = -1;
    AImove.bestRow = -1;

    game.printBoard();

    while(true) {
        std::cout << "Row: "; 
        std::cin >> row;
        std::cout << "Col: ";
        std::cin >> col;

        game.fillField(row, col, 'X');

        game.printBoard();
        
        AImove = game.bestMove();
        if(AImove.bestCol != -1 && AImove.bestRow != -1)
            game.fillField(AImove.bestRow + 1, AImove.bestCol + 1, 'O');
        game.printBoard();

        if((game.checkWin() == 10) || (game.checkWin() == -10) || (game.checkWin() == 0 && game.leftMove() == false))
            break;

    }



    return 0;
} 