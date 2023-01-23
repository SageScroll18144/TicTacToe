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
    char winner;

    SetTargetFPS(60); 
    
    // Main game loop
    while (!WindowShouldClose()) {
        winner = IsGameOver();

        // Update
        if(IsUserPlay() && !IsMark(getBoardPosition()) && winner=='-'){
            updatePiece(getBoardPosition(), turn);
            turn = !turn;
        }

        Vector2 bp = getBoardPosition();
        //if(IsUserPlay()) printf("(%d, %d)\n", (int)bp.x, (int)bp.y);

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);
            drawBoard();
            drawPiece();
            if(winner!='-') drawWindowWinner(winner);

        EndDrawing();


    }

    unLoadBoard();

    CloseWindow();      

    return 0;
}