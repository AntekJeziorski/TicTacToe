#include <iostream>
#include <bits/stdc++.h>
#include "board.hh"

int main() {

    board test(3);

    test.printBoard();

    test.fillField('X', 0, 0);

    test.printBoard();
    
    return 0;
} 