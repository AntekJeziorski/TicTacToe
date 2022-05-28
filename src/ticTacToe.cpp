#include "ticTacToe.hh"

ticTacToe::ticTacToe(int newSize, int newMaxDepth) {

    size = newSize;
    fields = new char*[size];

    for(int i = 0; i < size; i++) {
        fields[i] = new char[size];
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            fields[i][j] = ' ';
        }
    }

    maxDepth = newMaxDepth;

}

void ticTacToe::printBoard() {

    system("clear");

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

void ticTacToe::fillField(int row, int col, char ch) {

    fields[row-1][col-1] = ch;

}


int ticTacToe::checkWin() {
    
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            if (fields[i][j] != fields[i][j+1]) // sprawdzenie wygranej w wierszach
                break;
            if(j == size - 2) {    
                if (fields[i][0] == 'X')
                    return -10;
                else if (fields[i][0]=='O')
                    return 10;
            }
        }
    }
 
    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size - 1; j++) {
            if (fields[j][i] != fields[j+1][i]) // sprawdzenie wygranej w kolumnach
                break;
            if(j == size - 2) {    
                if (fields[0][i]=='X')
                    return -10;
                else if (fields[0][i]=='O')
                    return 10;
            }
            
        }
    }

    for(int i = 0; i < size-1; i++) {
        if(fields[i][i] != fields[i+1][i+1]) // sprawdzanie wygranej na pierwszej przekatnej
            break;
        if(i == size - 2) {
            if (fields[0][0]=='X')
                return -10;
            else if (fields[0][0]=='O')
                return 10;
        }
    }

    for(int i = 0; i < size - 1; i++){
        if(fields[size-i-1][i] != fields[size-i-2][i+1]) // sprawdzenie wygranej na drugiej przekątnej
            break;
        if(i == size - 2) {
            if (fields[size-1][0]=='X')
                return -10;
            else if (fields[size-1][0]=='O')
                return 10;
        }
    }
 
    return 0; // jesli nikt nie wygral zwroc 0
}

bool ticTacToe::leftMove() {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (fields[i][j] == ' ')
                return true;
    return false;
}

int ticTacToe::minMax(int depth, bool maxPlayer, int alpha, int beta) {

    int score = checkWin();

    if(depth == maxDepth) {
        if (maxPlayer)
        return score - depth;

        if (!maxPlayer)
        return score + depth;

        if (leftMove() == false)
        return 0;
    }

    if (score == 10)
        return score - depth;

    if (score == -10)
        return score + depth;

    if (leftMove() == false)
        return 0;

    if (maxPlayer) {
        int best = -1000;
 
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (fields[i][j] == ' ') {
                    fields[i][j] = 'O';
                    int val = minMax(depth + 1, false, alpha, beta);
                    best = std::max(best, val);
                    alpha = std::max(alpha, best);
                    fields[i][j] = ' ';
                    if (beta <= alpha)
                        break;
                }
                if (beta <= alpha)
                    break;
            }
        }

        return best;
    }
 
    else {

        int best = 1000;
 
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (fields[i][j]==' ') {
                    fields[i][j] = 'X';
                    int val = minMax(depth + 1, true, alpha, beta);
                    best = std::min(best, val);
                    beta = std::min(beta, best);
                    fields[i][j] = ' ';
                    if (beta <= alpha)
                        break;
                }
                if (beta <= alpha)
                    break;
            }
        }
        return best;
    }
}


move ticTacToe::bestMove() {

    int best = -1000;
    int moveVal = -1000;
    move bestMove;
    bestMove.bestRow = -1;
    bestMove.bestCol = -1;
 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (fields[i][j] == ' ') {
                fields[i][j] = 'O';
                moveVal = minMax(0, false, -1000, 1000);
                fields[i][j] = ' ';
                if (moveVal > best) {
                    bestMove.bestRow = i;
                    bestMove.bestCol = j;
                    best = moveVal;
                }
            }
        }
    }
 
    return bestMove;

}



