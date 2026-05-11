#pragma  once
#include <raylib.h>
#include <vector>
class Board{
    public:
        std::vector<Rectangle> board;
        
        Board();
        void CreateBoard();
        void Update();
        

};