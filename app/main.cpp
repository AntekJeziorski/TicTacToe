#include <iostream>
#include <bits/stdc++.h>
#include "ticTacToe.hh"

int main() {

    ticTacToe test(3);
    int row, col;
    
    test.printBoard();

    for(int i = 0; i < 100; i++) {
        std::cin >> row >> col ;

        test.fillField(row, col, 'X');

        test.printBoard();

        if(test.checkWin() == 10)
            break;
    }

    return 0;
} 