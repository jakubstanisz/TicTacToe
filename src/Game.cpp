#include "Game.hpp"
#include "Board.hpp"
#include <raylib.h>
Game::Game(int sW, int sH){
    screenWidth = sW;
    screenHeight = sH;
}
void Game::Init(){
    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");

}
void Game::Update(Board &board){
    Vector2 mousePosition = GetMousePosition();
    for(Rectangle square : board.board){
        if(CheckCollisionPointRec(mousePosition, square)){
            DrawRectangleRec(square, RED);
        }
    }
    
}
void Game::Draw(){
    Board board;
    board.CreateBoard();
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
        if( IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
            Update(board);
        }

        EndDrawing();
    }
    CloseWindow();
}
