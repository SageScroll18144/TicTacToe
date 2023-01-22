#include "raylib.h"
#include "board.h"
#include <stdio.h>

int main(void){
    // Initialization
    //--------------------------------------------------------------------------------------

    const int screenWidth = 400;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Tic Tac Toe!");

    initBoard();

    SetTargetFPS(60); 

    // Main game loop
    while (!WindowShouldClose()) {
        // Update

        printf("%d %d\n", GetMouseX(), GetMouseY());

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            drawBoard();

        EndDrawing();

    }

    unLoadBoard();

    CloseWindow();      

    return 0;
}