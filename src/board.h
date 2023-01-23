#ifndef BOARD_H
#define BOARD_H

#include "raylib.h"

typedef struct{
    Vector2 pos;
    char piece[1]; //string
}Object_pair;

typedef struct{
    Texture2D image; 
    Rectangle recSrc;
    Rectangle recDest;
    Vector2 vecOrigin;
    Object_pair board_image[9];
    int len_board_image;
    int state[3][3];
    char game[3][3];
    char winner;
}Board;

void initBoard(void);
void drawBoard(void);
void updatePiece(Vector2 positionOnBoard, int turn);
void drawPiece(void);
int IsMark(Vector2 positionOnBoard);
char IsGameOver(void);
void drawWindowWinner(char winner);
void putNodeOnGraphBoard(Board new_node, int idx);
Vector2 IAMachine(void);
void unLoadBoard(void);   

#endif //BOARD_H