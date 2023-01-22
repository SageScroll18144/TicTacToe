#include "raylib.h"
#include "board.h"

Board board;

void initBoard(void){
    board.image = LoadTexture("assets/tictactoe_board.png");

    board.recSrc = (Rectangle){0, 0, board.image.width, board.image.height};
    board.recDest = (Rectangle){0, 0, 400, 400};
    board.vecOrigin = (Vector2){0, 0};
}

void drawBoard(void){
    DrawTexturePro(board.image, board.recSrc, board.recDest, board.vecOrigin, 0, WHITE);
}

void unLoadBoard(void){
    UnloadTexture(board.image);
}