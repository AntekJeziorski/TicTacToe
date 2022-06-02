#include "ticTacToe.hh"

ticTacToe::ticTacToe(int newSize, int newMaxDepth, int newWinCharacters) {

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
    winCharacters = newWinCharacters;

}

void ticTacToe::printBoard() {

    system("clear"); // czyszczenie terminala

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
    
    for(int k = 0; k < size - winCharacters + 1; k++) {

        for (int i = 0; i < size; i++) {
            for(int j = k; j < winCharacters + k - 1; j++) {
                if (fields[i][j] != fields[i][j + 1]) // sprawdzenie wygranej w wierszach
                    break;
                if(j == winCharacters + k - 2) {    
                    if (fields[i][k] == 'X')
                        return -10;
                    else if (fields[i][k] == 'O')
                        return 10;
                }
            }
        }
    
        for (int i = 0; i < size; i++) {
            for(int j = k; j < winCharacters + k - 1; j++) {
                if (fields[j][i] != fields[j + 1][i]) // sprawdzenie wygranej w kolumnach
                    break;
                if(j == winCharacters + k - 2) {    
                    if (fields[k][i] == 'X')
                        return -10;
                    else if (fields[k][i] == 'O')
                        return 10;
                }
            }
        }
    }


    for(int k = 0; k < size - winCharacters + 1; k++) {
        for(int l = 0; l < size - winCharacters + 1; l++) {
            for(int i = 0; i < winCharacters - 1; i++) {
                if(fields[k + i][l + i] != fields[k + i + 1][l + i + 1]) // sprawdzanie wygranej na pierwszej przekatnej
                    break;
                if(i == winCharacters - 2) {
                    if (fields[k + i][l + i] == 'X')
                        return -10;
                    else if (fields[k + i][l + i] == 'O')
                        return 10;
                }
            }
        }
    }

    for(int k = 0; k < size - winCharacters + 1; k++) {
        for(int l = 0; l < size - winCharacters + 1; l++) {
            for(int i = 0; i < winCharacters - 1; i++){
                if(fields[size - i - k - 1][l + i] != fields[size - i - k - 2][l + i + 1]) // sprawdzenie wygranej na drugiej przekątnej
                    break;
                if(i == winCharacters - 2) {
                if (fields[size - i - k - 1][l + i] == 'X')
                    return -10;
                else if (fields[size - i - k - 1][l + i] == 'O')
                    return 10;
                }
            }
        }
    }

    return 0; // jesli nikt nie wygral zwroc 0
}

bool ticTacToe::leftMove() { // metoda sprawdzajaca czy zostaly wolne pola
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (fields[i][j] == ' ')
                return true;
    return false;
}

int ticTacToe::minMax(int depth, bool maxPlayer, int alpha, int beta) {

    int score = checkWin();

    if(depth == maxDepth) { // ograniczenie glebokosci rekurencji
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

    if (maxPlayer) { // jesli gra gracz maksymalizujacy
        int best = -1000;
 
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (fields[i][j] == ' ') {
                    fields[i][j] = 'O';
                    int tmp = minMax(depth + 1, false, alpha, beta);
                    best = std::max(best, tmp);
                    alpha = std::max(alpha, best); // szukaj alfy
                    fields[i][j] = ' ';
                    if (beta <= alpha)
                        break;
                }                   // jesli badany ruch jest gorszy od poprzedniego przestan przeszukiwac galaz
                if (beta <= alpha)
                    break;
            }
        }

        return best;
    }
 
    else { // jesli gra gracz minimalizujacy

        int best = 1000;
 
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (fields[i][j]==' ') {
                    fields[i][j] = 'X';
                    int tmp = minMax(depth + 1, true, alpha, beta);
                    best = std::min(best, tmp);
                    beta = std::min(beta, best); // szukaj bety
                    fields[i][j] = ' ';
                    if (beta <= alpha)
                        break;
                }                    // jesli badany ruch jest gorszy od poprzedniego przestan przeszukiwac galaz
                if (beta <= alpha)
                    break;
            }
        }
        return best;
    }
}


move ticTacToe::bestMove() { // wyszukiwanie najlepszego ruchu

    int best = -1000;
    int moveVal = -1000;
    move bestMove;
    bestMove.bestRow = -1;
    bestMove.bestCol = -1;
 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (fields[i][j] == ' ') {
                fields[i][j] = 'O';
                moveVal = minMax(0, false, -1000, 1000); // oblicz zakladany ruch
                fields[i][j] = ' ';
                if (moveVal > best) { // jesli ocena ruchu jest wieksza od najlepszej znalezionej
                    bestMove.bestRow = i; // przypisz wspolrzedne ruchu
                    bestMove.bestCol = j;
                    best = moveVal; // oraz ustal nowa najlepsza wartosc
                }
            }
        }
    }
 
    return bestMove; // zwroc najlepszy ruch

}



