#include <iostream>
#include "raylib.h"
#include "Game.hpp"
#include "Board.hpp"

int main(){
    int screenWidth = 900;
    int screenHeight = 900;
    Game game(screenWidth, screenHeight);
    game.Init();
    game.Draw();

    return 0;
}