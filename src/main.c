#include "raylib.h"
#include "board.h"
#include "user.h"
#include <stdio.h>

int main(void){
    // Initialization
    //--------------------------------------------------------------------------------------

    const int screenWidth = 400;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Tic Tac Toe!");

    initBoard();

    int turn = 1;

    SetTargetFPS(60); 
    
    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        if(IsUserPlay() && IsMark(getBoardPosition())){
            updatePiece(getBoardPosition(), turn);
            turn = !turn;
        }
        //printf("%d %d\n", GetMouseX(), GetMouseY());

        Vector2 bp = getBoardPosition();
        if(IsUserPlay()) printf("(%d, %d)\n", (int)bp.x, (int)bp.y);

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);
            drawBoard();
            DrawText("JKHFDLA", 200, 200, 20, BLACK);
            drawPiece();
            

        EndDrawing();

    }

    unLoadBoard();

    CloseWindow();      

    return 0;
}