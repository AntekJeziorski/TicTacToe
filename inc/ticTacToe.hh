#include <iostream>

class ticTacToe {

    private:
        int size;
        char** fields;
    public:
        ticTacToe(){}
        ticTacToe(int newSize);
        void printBoard();
        void fillField(int row, int col, char ch);
        int checkWin();
        int minMax();
};

struct move {

    int row, col;

};