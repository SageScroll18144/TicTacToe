#include "raylib.h"
#include "board.h"
#include <stdio.h>

Board board;

void initBoard(void){
    board.image = LoadTexture("assets/tictactoe_board.png");

    board.recSrc = (Rectangle){0, 0, board.image.width, board.image.height};
    board.recDest = (Rectangle){0, 0, 400, 400};
    board.vecOrigin = (Vector2){0, 0};

    board.len_board_image=0;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) board.state[i][j]=0;
}

void drawBoard(void){
    DrawTexturePro(board.image, board.recSrc, board.recDest, board.vecOrigin, 0, WHITE);
}

void updatePiece(Vector2 positionOnBoard, int turn){
    int x = (int)positionOnBoard.x;
    int y = (int)positionOnBoard.y;

    int real_pos_x, real_pos_y;

    if(x == 0) real_pos_x = 50;
    else if(x == 1) real_pos_x = 180;
    else real_pos_x = 290;
    
    if(y == 0) real_pos_y = 60;
    else if(y == 1) real_pos_y = 190;
    else real_pos_y = 300;

    Font font = LoadFont("fonts/jupiter_crash.png");

    if(turn) {
        board.board_image[board.len_board_image++] = (Object_pair){real_pos_y, real_pos_x, "X"};
    }
    else board.board_image[board.len_board_image++] = (Object_pair){real_pos_y, real_pos_x, "O"};

    board.state[x][y] = 1;
}

void drawPiece(void){
    Font font = LoadFont("fonts/jupiter_crash.png");
    printf("-> %d\n", board.len_board_image);
    for(int i=0;i<board.len_board_image;i++){
        DrawTextEx(font, board.board_image[i].piece, board.board_image[i].pos, 60, 1, DARKGRAY);
    }
}

int IsMark(Vector2 positionOnBoard){
    return board.state[(int)positionOnBoard.x][(int)positionOnBoard.y];
}

void unLoadBoard(void){
    UnloadTexture(board.image);
}