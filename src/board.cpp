#include "board.hh"

board::board(int newSize) {

    size = newSize;
    fields = new char*[size];

    for(int i = 0; i < size; i++) {
        fields[i] = new char[size];
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            fields[i][j] = '.';
        }
    }

}

void board::printBoard() {

    std::cout << "\t";

    for(int i = 0; i < size; i++) {
        std::cout << i + 1 << "\t";
    }
    std::cout << std::endl;

    for(int i = 0; i < size; i++) {
        std::cout << i+1 << "\t";
        for(int j = 0; j < size; j++) {
            std::cout << fields[i][j] << "\t"; 
        }
        std::cout << std::endl;
    }
}

void board::fillField(char x, int i, int j) {

    fields[i][j] = x;

}