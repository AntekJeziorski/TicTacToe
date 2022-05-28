#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>

struct move {

    int bestRow, bestCol;

};

class ticTacToe {

    private:
        int size;
        char** fields;
        int maxDepth;
    public:
        ticTacToe(){}
        ticTacToe(int newSize, int newMaxDepth);
        void printBoard();
        void fillField(int row, int col, char ch);
        int checkWin();
        bool leftMove();
        int minMax(int depth, bool maxPlayer, int alpha, int beta);
        move bestMove();

};

