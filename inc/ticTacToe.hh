#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>

struct move {   // struktura przetrzymujaca wspolrzedne ruchu AI

    int bestRow, bestCol;

};

class ticTacToe { // klasa sluzaca do obslugi gry oraz przetrzymujaca jej parametry

    private:
        int size;   // rozmiar gry
        char** fields;  // pola
        int maxDepth;   // maksymalna glebokosc przeszukiwania drzewa
        int winCharacters;  // ilosc znakow potrzebna do wygrania
    public:
        ticTacToe(){}   //konstruktor bezparametryczny
        ticTacToe(int newSize, int newMaxDepth, int newWinCharacters);  // konstruktor parametryczny, tworzy gre o okreslonym rozmiarze i okreslonej ilosci znakow potrzebnych do wygranej
        void printBoard();  // wyswietlanie gry
        void fillField(int row, int col, char ch);  // wypelnianie pola
        int checkWin(); //metoda sprawdzajaca wygrana, jesli remis zwroc 0, jesli wygrywa gracz maksymalizujac zwroc 10, jesli minimalizujacy zwroc -10
        bool leftMove();    // metoda sprawdzajaca czy pozostaly wolne pola, jesli tak zwroc true, jesli nie zwroc false
        int minMax(int depth, bool maxPlayer, int alpha, int beta); // metoda wykonujaca algorytm MinMax
        move bestMove();    // metoda wyszukujaca najlepszy ruch AI wykorzystujaca metode minMax

};

