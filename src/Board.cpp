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