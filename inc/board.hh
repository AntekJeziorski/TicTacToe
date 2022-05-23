#include <iostream>

class board {

    private:
        int size;
        char** fields;
    public:
        board(){}
        board(int newSize);
        void printBoard();
        void fillField(char x, int i, int j);

};