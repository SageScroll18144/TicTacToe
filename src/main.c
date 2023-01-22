#include "raylib.h"

int main(void){
    // Initialization
    //--------------------------------------------------------------------------------------

    const int screenWidth = 400;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Tic Tac Toe!");

    Texture2D board = LoadTexture("assets/tictactoe_board.png");

    Rectangle recSrc = {0, 0, board.width, board.height};
    Rectangle recDest = {0, 0, 400, 400};
    Vector2 vecOrigin = {0, 0};

    SetTargetFPS(60); 

    // Main game loop
    while (!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexturePro(board, recSrc, recDest, vecOrigin, 0, WHITE);

        EndDrawing();

    }

    UnloadTexture(board);

    CloseWindow();      

    return 0;
}