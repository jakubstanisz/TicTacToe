#pragma once
#include "Board.hpp"

class Game{
    private:
        int screenWidth;
        int screenHeight;

    public:
        Game(int screenWidth, int screenHeight);
        void Init();
        void Update(Board &board);
        void Draw();

};