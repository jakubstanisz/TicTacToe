#include "Board.hpp"
#include <raylib.h>
#include <vector>

Board::Board(){};

void Board::CreateBoard(){
    float cellSize = 300;
    for (float i {0}; i < 3; i++){
        for(float j {0}; j < 3; j++){
            board.push_back({j * cellSize, i * cellSize,  cellSize, cellSize});
        }
    }
}

int Board::CheckIfEnd(int (&tab)[9]){
    const int winConditions[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Poziomy
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Piony
    {0, 4, 8}, {2, 4, 6}             // Skosy
    };

    for (int i {}; i < 9; i++){
        int a = winConditions[i][0];
        int b = winConditions[i][1];
        int c = winConditions[i][2];

        if (tab[a] != 0  && tab[a] == tab[b] && tab[a] == tab[c] ){
            return tab[a];
        }
    }
    return 0;
}