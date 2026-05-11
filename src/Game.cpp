#include "Game.hpp"
#include <raylib.h>
Game::Game(int sW, int sH){
    screenWidth = sW;
    screenHeight = sH;
}
void Game::Init(){
    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");

}
void Game::Update(){

}
void Game::Draw(){
    float sizeOfSquare = (float)screenWidth / 3;
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        // Drawing grid 3x3 squares
        for (int i{1}; i < 4; i++){
            DrawLineEx({sizeOfSquare * i, 0},
                {sizeOfSquare * i, (float)screenHeight}, 10.0, BLACK);   
        }
        for (int i{1}; i < 4; i++){
            DrawLineEx({0, sizeOfSquare * i},
                {(float)screenWidth,sizeOfSquare * i}, 10.0, BLACK);
        }

        EndDrawing();
    }
    CloseWindow();
}
