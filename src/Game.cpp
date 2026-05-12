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
void Game::Update(Board &board, RenderTexture2D &canvas, int (&tab)[9]){
    Vector2 mousePosition = GetMousePosition();
    static bool swapPlayer {false};
    float sizeOfSquare = (float)screenWidth / 3;
    for(int i {}; i < 9; i++){
        Rectangle square = board.board[i];

        if(CheckCollisionPointRec(mousePosition, square) && tab[i] == 0){
            BeginTextureMode(canvas);
            if(!swapPlayer){
                DrawLineEx({square.x, square.y}, 
                    {square.x + sizeOfSquare,square.y + sizeOfSquare }, 10.0,RED);
                DrawLineEx({square.x, square.y + sizeOfSquare}, 
                    {square.x + sizeOfSquare, square.y}, 10.0, RED);
                tab[i] = 1;
            }else if (swapPlayer){
                DrawCircleV({square.x + (sizeOfSquare/2), square.y + (sizeOfSquare/2)},
                sizeOfSquare/2 - 5, RED);
                DrawCircleV({square.x + (sizeOfSquare/2), square.y + (sizeOfSquare/2)},
                    sizeOfSquare/2 - 20, WHITE);  
                tab[i] = 2;
            }
            EndTextureMode();
            swapPlayer = !swapPlayer;
        }

    }
 
}
void Game::Draw(){
    Board board;
    board.CreateBoard();
    int tab[9] = {0};
    float sizeOfSquare = (float)screenWidth / 3;

    RenderTexture2D canvas = LoadRenderTexture(screenWidth, screenHeight);

    BeginTextureMode(canvas);
    ClearBackground(BLANK);
    EndTextureMode();

    while(!WindowShouldClose()){
        if( IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
            Update(board, canvas,tab);
        }
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

        DrawTextureRec(canvas.texture, 
            {0, 0, (float)canvas.texture.width, (float)-canvas.texture.height}, 
            {0, 0}, WHITE);
            int winner = board.CheckIfEnd(tab);
        if (winner != 0) {
            BeginTextureMode(canvas);
            ClearBackground(BLANK);
            if (winner == 1) {
                DrawText("Cross Won", screenWidth /2 - 130, screenHeight /2 - 50, 
                    50, BLUE);
                } else {
                    DrawText("Circle Won", screenWidth /2 - 130, screenHeight /2 - 50,
                        50, BLUE);
                }
            EndTextureMode();
        }
        EndDrawing();
    }
    UnloadRenderTexture(canvas);
    CloseWindow();
}
