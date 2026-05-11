#include <iostream>
#include "raylib.h"
int main(){
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}