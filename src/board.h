#ifndef BOARD_H
#define BOARD_H

#include "raylib.h"

typedef struct{
    Texture2D image; 
    Rectangle recSrc;
    Rectangle recDest;
    Vector2 vecOrigin;
}Board;

void initBoard(void);
void drawBoard(void);
void unLoadBoard(void);

#endif BOARD_H